
#  EasyPark - Integração de Endpoints

##  Integrantes
- Vinicius da Silva Bitú — RM 560227  
- Kauã Ferreira dos Santos — RM 560992  
- Gabriel Cruz Ferreira — RM 559613  

---

##  FIAP  
Curso: Análise e Desenvolvimento de Sistemas  

---

#  Sprint 04 - Integração de Endpoints

---

## 1. Introdução

O projeto EasyPark foi desenvolvido com o objetivo de facilitar o gerenciamento inteligente de vagas de estacionamento.

Nesta Sprint 04, o foco principal foi integrar toda a arquitetura do sistema, conectando:

- API REST
- Banco de Dados Oracle
- Comunicação em nuvem

Além disso, a aplicação foi disponibilizada publicamente utilizando ngrok, permitindo testes externos em tempo real.

---

## 2. Problema

Muitos sistemas de estacionamento funcionam de maneira separada, dificultando a comunicação entre sensores, banco de dados e aplicações administrativas.

Isso gera problemas como:

- dificuldade para monitorar vagas
- baixa integração entre sistemas
- pouca automação
- dificuldade de gerenciamento

A proposta da Sprint foi centralizar todos os serviços em uma única API integrada.

---

## 3. Tecnologias Utilizadas

O sistema foi desenvolvido utilizando:

- Python
- Flask
- Oracle Database
- Pandas
- Pyngrok
- Threading

---

## 4. Banco de Dados

O projeto utiliza Oracle Database para armazenamento das informações do sistema.

Foram realizadas integrações para:

- autenticação de usuários
- consulta de dados
- listagem de usuários
- dashboard gerencial

A conexão foi feita utilizando a biblioteca `oracledb` em modo Thin.

---

## 5. Dados Utilizados

Os dados utilizados foram simulados em CSV representando sensores IoT.

Os arquivos possuem informações como:

- id da vaga
- horário
- status da vaga
- tempo de ocupação
- data
- dia da semana


---

## 6. Arquitetura

O sistema funciona da seguinte forma:

```text
Usuário
↓
API Flask (EasyPark)
↓
Dados CSV / Oracle
↓
Resposta ao usuário
````

---

## 7. Endpoints da API

### GET /

Verifica se o servidor está online.

### GET /usuarios

Lista usuários cadastrados no banco Oracle.

### POST /login

Realiza autenticação de usuários.

### POST /dados

Recebe e processa dados do sistema.

### GET /dashboard

Apresenta informações gerenciais do sistema.

---

## 8. Fluxo de Funcionamento

1. O usuário envia uma requisição
2. O Flask recebe a solicitação
3. O sistema carrega os dados CSV
4. Os dados são processados
5. As informações são retornadas ao usuário

Exemplo:

```text
Consulta de vagas disponíveis
```

---

## 9. Benefícios

* Melhor organização do sistema
* Respostas rápidas
* Integração com Oracle
* Estrutura preparada para mobile/web
* API centralizada

---

## 10. Conclusão

A Sprint 04 permitiu integrar banco Oracle e API REST em uma única aplicação funcional.

O projeto EasyPark evoluiu para uma arquitetura mais organizada e preparada para futuras melhorias.

Entre as possibilidades futuras estão:

* integração com sensores reais
* dashboards avançados
* aplicativo mobile
* monitoramento em tempo real

---

## Vídeo

[https://youtu.be/mS-_IpAb7U0]((https://youtu.be/T9HBWm6LfLQ))

```

