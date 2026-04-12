# 🚗 EasyPark - IA

## 👨‍💻 Integrantes
- Vinicius da Silva Bitú — RM 560227  
- Kauã Ferreira dos Santos — RM 560992  
- Gabriel Cruz Ferreira — RM 559613  

---

## 🎓 FIAP  
Curso: Análise e Desenvolvimento de Sistemas  

---

## 🚀 Sprint 03 - Inteligência Artificial

---

## 1. Introdução

O projeto EasyPark tem como ideia ajudar no controle de vagas de estacionamento.

Ele usa tecnologias como API, banco Oracle e agora também Inteligência Artificial.

Nessa sprint, a gente adicionou uma IA pra deixar o sistema mais inteligente e fácil de usar.

---

## 2. Problema

Hoje é difícil saber se tem vaga livre ou não em tempo real.

A ideia foi usar IA pra responder isso de forma rápida, tipo:

- "Tem vaga livre?"
- "Quantas vagas estão ocupadas?"

---

## 3. Modelo de IA

A gente usou um modelo LLM (tipo ChatGPT) com a API da OpenAI.

Motivo:
- entende perguntas normais (tipo conversa)
- fácil de usar
- não precisa treinar muito

---

## 4. Dados usados

Os dados foram criados em CSV simulando sensores IoT.

Tem coisas tipo:
- id da vaga  
- horário  
- dia da semana  
- status (livre ou ocupado)  
- tempo de uso  

Isso simula sensores reais de estacionamento.

---

## 5. Arquitetura

O sistema funciona assim:

Usuário
↓
Aplicação (EasyPark)
↓
IA (OpenAI)
↓
Dados (CSV ou banco)
↓
Resposta

---

## 6. Como funciona

1. Usuário faz uma pergunta  
2. Sistema recebe  
3. Pega os dados  
4. Envia pra IA  
5. IA analisa  
6. Responde  

Exemplo:
"Quantas vagas estão livres?"

---

## 7. Benefícios

- Resposta rápida  
- Mais fácil pro usuário  
- Sistema mais inteligente  
- Pode melhorar no futuro  

---

## 8. Conclusão

A IA ajudou a deixar o EasyPark mais moderno.

Agora o sistema consegue responder perguntas ao invés de só mostrar dados.

No futuro dá pra melhorar com dados reais e sensores de verdade.

---

## 🎥 Vídeo

([https://youtu.be/mS-_IpAb7U0](https://youtu.be/mS-_IpAb7U0))

---




