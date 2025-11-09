/////////--------IOT--------FIAP------------///////////
// LÓGICA DE VAGA DE ESTACIONAMENTO
// VERSÃO COM SIMULADOR DE 2 VAGAS (A-01 e A-02)
///////////////////////////////////////////////////////

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

// Configurações de WiFi
const char *SSID = "Wokwi-GUEST";
const char *PASSWORD = "";

// Configurações de MQTT
const char *BROKER_MQTT = "broker.hivemq.com";
const int BROKER_PORT = 1883;
const char *ID_MQTT = "EasyPark_ESP32_Simulador"; // Mude se der loop de conexão
const char *TOPIC_PUBLISH_VAGA = "EasyPark_vaga";

// Configurações de Hardware
#define PIN_LED 15
#define PUBLISH_DELAY 10000 // 10 segundos

// Variáveis globais
WiFiClient espClient;
PubSubClient MQTT(espClient);
unsigned long publishUpdate = 0;
const int TAMANHO = 200;

// <-- MUDANÇA 2 VAGAS: Variáveis para guardar o estado das 2 vagas
bool statusVagaA01 = false; // Começa como 'livre'
bool statusVagaA02 = true;  // Começa como 'ocupado' (para não mudarem ao mesmo tempo)
bool vezDaVagaA01 = true;   // Controla de quem é a vez de mudar

// Protótipos de funções
void initWiFi();
void initMQTT();
void callbackMQTT(char *topic, byte *payload, unsigned int length);
void reconnectMQTT();
void reconnectWiFi();
void checkWiFIAndMQTT();


void initWiFi() {
  Serial.print("Conectando com a rede: ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Conectado com sucesso: ");
  Serial.println(SSID);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void initMQTT() {
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  MQTT.setCallback(callbackMQTT);
}

void callbackMQTT(char *topic, byte *payload, unsigned int length) {
  String msg = String((char*)payload).substring(0, length);
  Serial.printf("Mensagem recebida [tópico %s]: %s\n", topic, msg.c_str());
}

void reconnectMQTT() {
  while (!MQTT.connected()) {
    Serial.print("Tentando conectar com o Broker MQTT: ");
    Serial.println(BROKER_MQTT);

    if (MQTT.connect(ID_MQTT)) {
      Serial.println("Conectado ao broker MQTT!");
    } else {
      Serial.println("Falha na conexão com MQTT. Tentando novamente em 2 segundos.");
      delay(2000);
    }
  }
}

void checkWiFIAndMQTT() {
  if (WiFi.status() != WL_CONNECTED) reconnectWiFi();
  if (!MQTT.connected()) reconnectMQTT();
}

void reconnectWiFi(void)
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Wifi conectado com sucesso");
  Serial.print(SSID);
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT); // O LED agora só pisca para mostrar atividade
  initWiFi();
  initMQTT();
}


// <-- MUDANÇA 2 VAGAS: Lógica do loop para alternar a simulação
void loop() {
  checkWiFIAndMQTT();
  MQTT.loop();

  // A lógica de delay principal agora é de 10 segundos
  if ((millis() - publishUpdate) >= PUBLISH_DELAY) {
    publishUpdate = millis();
    
    // Pisca o LED para mostrar que está enviando dados
    digitalWrite(PIN_LED, HIGH);
    delay(100);
    digitalWrite(PIN_LED, LOW);

    // Variáveis para o JSON
    String idVagaParaEnviar;
    bool statusParaEnviar;

    // 1. LÓGICA DE SIMULAÇÃO:
    //    Verifica de qual vaga é a vez de atualizar
    if (vezDaVagaA01) {
      statusVagaA01 = !statusVagaA01; // Inverte o status da A-01
      idVagaParaEnviar = "A-01";
      statusParaEnviar = statusVagaA01;
      vezDaVagaA01 = false; // Próxima vez será da A-02
      Serial.println("Simulando Vaga: A-01");
      
    } else {
      statusVagaA02 = !statusVagaA02; // Inverte o status da A-02
      idVagaParaEnviar = "A-02";
      statusParaEnviar = statusVagaA02;
      vezDaVagaA01 = true; // Próxima vez será da A-01
      Serial.println("Simulando Vaga: A-02");
    }

    // 2. Monta o JSON para publicar
    JsonDocument doc;
    doc["id_vaga"] = idVagaParaEnviar;
    doc["status"] = statusParaEnviar ? "ocupado" : "livre";

    char buffer[TAMANHO];
    serializeJson(doc, buffer);

    // 3. Publica a mudança no tópico MQTT
    MQTT.publish(TOPIC_PUBLISH_VAGA, buffer);
    Serial.print("Publicado no MQTT: ");
    Serial.println(buffer);
  }
}