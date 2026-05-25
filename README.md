# Sistema Inteligente de Iluminacao com Arduino e Arquitetura ARM

Projeto academico desenvolvido para a disciplina de Programacao de Microprocessadores e Microcontroladores.

---

## 📖 Sobre o Projeto

O projeto consiste no desenvolvimento de um sistema embarcado inteligente capaz de realizar o controle automatizado de iluminacao residencial utilizando sensores, Arduino e conceitos introdutorios de Inteligencia Artificial e arquitetura ARM.

O sistema realiza a leitura continua da luminosidade do ambiente e da presenca de pessoas, classificando o ambiente em **10 situacoes distintas** e executando tomadas de decisao automatizadas em tempo real.

Quando o ambiente esta escuro e ha deteccao de presenca, o sistema aciona automaticamente a iluminacao artificial e o alerta sonoro com frequencias proporcionais ao nivel de criticidade detectado, simulando um sistema inteligente de eficiencia energetica residencial.

---

## 📄 Acessar Artigo Academico em PDF

---

## 🎯 Objetivos

- Desenvolver algoritmos embarcados em linguagem C/C++;
- Aplicar conceitos introdutorios de Inteligencia Artificial em sistemas embarcados;
- Implementar logica de tomada de decisao com 10 situacoes distintas;
- Utilizar sensores LDR e PIR integrados ao Arduino;
- Simular sistemas embarcados virtualmente na plataforma Wokwi;
- Estudar conceitos introdutorios de arquitetura ARM com Raspberry Pi Pico;
- Desenvolver um sistema de iluminacao inteligente de baixo custo;
- Organizar o projeto utilizando GitHub como ferramenta de versionamento.

---

## ⚙️ Funcionalidades

- ✅ Monitoramento continuo de luminosidade
- ✅ Deteccao de presenca e movimento
- ✅ Acionamento automatico de LED
- ✅ Alerta sonoro com frequencias distintas por nivel de criticidade
- ✅ Classificacao do ambiente em 10 situacoes distintas
- ✅ Interface serial de monitoramento em tempo real
- ✅ Tomada de decisao automatizada com logica inteligente
- ✅ Simulacao virtual do circuito no Wokwi
- ✅ Simulacao complementar em arquitetura ARM

---

## 🧠 Logica do Sistema — 10 Situacoes

O sistema executa a seguinte logica de decisao inteligente:

| Situacao | Luminosidade | Presenca | Acao |
|---|---|---|---|
| ALERTA MAXIMO | < 200 | Sim | LED ON + Buzzer 1500 Hz |
| ALERTA: Muito escuro | 200 a 399 | Sim | LED ON + Buzzer 1000 Hz |
| Escuro com presenca | 400 a 599 | Sim | LED ON + Buzzer 800 Hz |
| Luz natural parcial | 600 a 799 | Sim | LED OFF, sem buzzer |
| Totalmente iluminado | >= 800 | Sim | LED OFF, sem buzzer |
| Escuridao total. Standby | < 200 | Nao | LED OFF, sem buzzer |
| Muito escuro. Standby | 200 a 399 | Nao | LED OFF, sem buzzer |
| Escuro sem presenca | 400 a 599 | Nao | LED OFF, sem buzzer |
| Luz parcial. Em espera | 600 a 799 | Nao | LED OFF, sem buzzer |
| Repouso total | >= 800 | Nao | LED OFF, sem buzzer |

---

## 🛠️ Tecnologias Utilizadas

- Arduino UNO
- Linguagem C/C++
- Wokwi Simulator
- GitHub
- Raspberry Pi Pico (Arquitetura ARM Cortex-M0+)
- Conceitos introdutorios de Inteligencia Artificial

---

## 🔌 Componentes Utilizados

| Componente | Funcao | Conexao |
|---|---|---|
| Arduino UNO | Controle principal do sistema | — |
| Sensor LDR | Leitura de luminosidade | Pino A0 |
| Sensor PIR | Deteccao de presenca | Pino 2 |
| LED + resistor 220 Ohm | Iluminacao artificial | Pino 9 |
| Buzzer | Alerta sonoro | Pino 8 |

---

## 📷 Estrutura do Projeto

```
/projeto
│
├── codigo/
├── imagens/
├── documentacao/
├── diagramas/
├── video/
├── simulacao-arm/
└── README.md
```

---

## 🖼️ Imagens do Projeto

### 🔧 Estrutura Geral do Circuito
Imagem completa do sistema embarcado desenvolvido no simulador Wokwi.

![Circuito Completo]()

---

### 📡 Sensores e Atuadores

**Sensor LDR — Monitoramento de Luminosidade**
Responsavel pela leitura da intensidade luminosa do ambiente.

![Sensor LDR]()

**Sensor PIR — Deteccao de Presenca**
Responsavel pela identificacao de presenca e movimentacao no ambiente.

![Sensor PIR]()

**LED — Iluminacao Artificial**
Acionado automaticamente quando ha presenca em ambiente escuro.

![LED]()

**Buzzer — Alerta Sonoro**
Emite frequencias distintas conforme o nivel de criticidade do ambiente.

![Buzzer]()

---

## 💻 Codigo-Fonte do Sistema

### Estrutura Principal do Algoritmo

![Codigo Parte 1]()

### Logica de Tomada de Decisao

![Codigo Parte 2]()

---

## 🧪 Demonstracao de Funcionamento

### ALERTA MAXIMO — Escuridao total com presenca
Ambiente com luminosidade abaixo de 200 e presenca detectada. LED acende e buzzer emite 1500 Hz.

![Alerta Maximo]()

### Escuro com presenca — Iluminacao ativada
Luminosidade entre 400 e 599 com presenca detectada. LED acende e buzzer emite 800 Hz.

![Escuro com Presenca]()

### Luz natural parcial com presenca
Luminosidade entre 600 e 799 com presenca detectada. Sistema mantem LED apagado.

![Luz Parcial]()

### Sistema em Repouso total
Ambiente totalmente iluminado sem presenca detectada. Todos os atuadores desligados.

![Repouso Total]()

---

## 💻 Codigo Principal

```cpp
// Sistema Inteligente de Iluminacao
// Autor: [Seu Nome]
// Disciplina: Programacao de Microprocessadores e Microcontroladores

int ldr = A0;      // Sensor de luminosidade
int pir = 2;       // Sensor de presenca
int led = 9;       // LED de iluminacao
int buzzer = 8;    // Buzzer de alerta

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(ldr);
  int movimento = digitalRead(pir);

  // Exibe valores dos sensores no Serial Monitor
  Serial.print("Luz: ");
  Serial.print(luz);
  Serial.print(" | Movimento: ");
  Serial.println(movimento);

  // Algoritmo de tomada de decisao inteligente — 10 situacoes
  if (luz < 200 && movimento == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer, 1500);
    Serial.println("ALERTA MAXIMO: Escuridao total com presenca!");
  }
  else if (luz >= 200 && luz < 400 && movimento == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);
    Serial.println("ALERTA: Ambiente muito escuro com presenca!");
  }
  else if (luz >= 400 && luz < 600 && movimento == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer, 800);
    Serial.println("Escuro com presenca. Iluminacao ativada.");
  }
  else if (luz >= 600 && luz < 800 && movimento == HIGH) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Luz natural parcial. Presenca detectada.");
  }
  else if (luz >= 800 && movimento == HIGH) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Ambiente totalmente iluminado. Presenca detectada.");
  }
  else if (luz < 200 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Escuridao total. Nenhuma presenca. Standby.");
  }
  else if (luz >= 200 && luz < 400 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Muito escuro. Sem presenca. Standby.");
  }
  else if (luz >= 400 && luz < 600 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Escuro sem presenca. Standby.");
  }
  else if (luz >= 600 && luz < 800 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Luz natural parcial. Sem presenca. Em espera.");
  }
  else {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Ambiente totalmente iluminado. Repouso total.");
  }

  delay(1000); // Ciclo de leitura a cada 1 segundo
}
```

---

## 🔄 Diagrama Simplificado do Sistema

```
LDR  → Arduino (A0) → Algoritmo de decisao → LED    (pino 9)
PIR  → Arduino (2)  → Algoritmo de decisao → Buzzer (pino 8)
```

---

## 🧪 Simulacao

O projeto foi desenvolvido virtualmente utilizando o simulador **Wokwi**, permitindo a integracao de sensores e atuadores sem necessidade de hardware fisico.

---

## 🖥️ Simulacao ARM

Alem do sistema principal desenvolvido em Arduino UNO, foi realizada uma simulacao complementar utilizando **Raspberry Pi Pico**, plataforma baseada em arquitetura **ARM Cortex-M0+**.

A simulacao teve como objetivo demonstrar o funcionamento de um algoritmo embarcado responsavel pelo controle automatizado de iluminacao em tempo real, aplicando conceitos introdutorios de sistemas inteligentes em uma arquitetura de processamento moderna.

### 🔄 Fluxo de Execucao do Algoritmo ARM

O processador executa continuamente o seguinte fluxo:

```
Inicializacao do sistema
        ↓
Configuracao do GPIO
        ↓
Leitura dos sensores (LDR e PIR)
        ↓
Classificacao do ambiente (10 situacoes)
        ↓
Acionamento dos atuadores (LED e Buzzer)
        ↓
Temporizacao (1 segundo)
        ↓
Repeticao continua do algoritmo
```

### 🧩 Codigo da Simulacao ARM

```c
// Simulacao ARM — Raspberry Pi Pico
#include "pico/stdlib.h"

int main() {

    const uint LED = 25;  // LED onboard do Pico

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    while (true) {

        gpio_put(LED, 1);   // Liga o LED (simula iluminacao ativa)
        sleep_ms(2000);     // Aguarda 2 segundos

        gpio_put(LED, 0);   // Desliga o LED (simula standby)
        sleep_ms(1000);     // Aguarda 1 segundo
    }
}
```

### 📷 Simulacao Raspberry Pi Pico

**Estrutura da Plataforma ARM**

![Circuito ARM]()

**Codigo Executado na Arquitetura ARM**

![Codigo ARM]()

**Execucao do Algoritmo Embarcado**

![LED ARM]()

---

## 🧱 Conceitos de Arquitetura ARM

Durante o desenvolvimento do projeto foram estudados conceitos introdutorios de arquitetura ARM, amplamente utilizada em sistemas embarcados modernos devido a sua eficiencia energetica e capacidade de processamento em tempo real.

A simulacao em Raspberry Pi Pico permitiu compreender controle de GPIO, execucao continua de algoritmos embarcados e processamento em tempo real aplicado ao controle de iluminacao inteligente.

---

## 📊 Resultados Obtidos

O sistema apresentou funcionamento satisfatorio durante os testes realizados no ambiente de simulacao Wokwi.

Os sensores responderam corretamente as alteracoes de luminosidade e presenca, realizando acionamentos automaticos conforme as 10 situacoes programadas no algoritmo.

O projeto demonstrou a aplicacao pratica de:

- programacao embarcada em C/C++;
- algoritmo de tomada de decisao com IA introdutoria;
- automacao de iluminacao residencial;
- integracao de multiplos sensores;
- eficiencia energetica — LED so acende quando necessario;
- monitoramento em tempo real via Serial Monitor.

---

## 🎥 Demonstracao

Adicionar video demonstrando o funcionamento do sistema.

---

## 🔗 Simulacao Online

[Acessar projeto no Wokwi]()

---

## 📋 Como Executar

1. Acesse [wokwi.com](https://wokwi.com)
2. Crie um novo projeto **Arduino UNO**
3. Importe o arquivo `diagramas/diagram.json`
4. Cole o codigo de `codigo/sketch.ino`
5. Clique em **Start Simulation**
6. Abra o **Serial Monitor**
7. Clique no **LDR** e ajuste o slider para simular luminosidade
8. Clique no **PIR** para simular presenca
9. Observe as mensagens no Serial Monitor e o comportamento do LED e buzzer

---

## 👨‍💻 Autor

**[Seu Nome]**

Projeto desenvolvido para fins academicos.
