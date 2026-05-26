int ldr = A0;
int pir = 2;
int led = 9;
int buzzer = 8;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(ldr);
  int movimento = digitalRead(pir);

  Serial.print("Luz: ");
  Serial.print(luz);
  Serial.print(" | Movimento: ");
  Serial.println(movimento);

  // ESCURIDAO TOTAL + PRESENCA = maximo alerta
  if (luz < 200 && movimento == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer, 1500);
    Serial.println("ALERTA MAXIMO: Escuridao total com presenca detectada!");
  }
  // MUITO ESCURO + PRESENCA
  else if (luz >= 200 && luz < 400 && movimento == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);
    Serial.println("ALERTA: Ambiente muito escuro com presenca detectada!");
  }
  // ESCURO + PRESENCA
  else if (luz >= 400 && luz < 600 && movimento == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer, 800);
    Serial.println("Escuro com presenca detectada. Iluminacao ativada.");
  }
  // LUZ PARCIAL + PRESENCA
  else if (luz >= 600 && luz < 800 && movimento == HIGH) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Luz natural parcial. Presenca detectada. Iluminacao dispensada.");
  }
  // TOTALMENTE ILUMINADO + PRESENCA
  else if (luz >= 800 && movimento == HIGH) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Ambiente totalmente iluminado. Presenca detectada.");
  }
  // ESCURIDAO TOTAL + SEM PRESENCA
  else if (luz < 200 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Escuridao total. Nenhuma presenca. Standby.");
  }
  // MUITO ESCURO + SEM PRESENCA
  else if (luz >= 200 && luz < 400 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Muito escuro. Sem presenca. Standby.");
  }
  // ESCURO + SEM PRESENCA
  else if (luz >= 400 && luz < 600 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Escuro sem presenca. Standby.");
  }
  // LUZ PARCIAL + SEM PRESENCA
  else if (luz >= 600 && luz < 800 && movimento == LOW) {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Luz natural parcial. Sem presenca. Sistema em espera.");
  }
  // TOTALMENTE ILUMINADO + SEM PRESENCA
  else {
    digitalWrite(led, LOW);
    noTone(buzzer);
    Serial.println("Ambiente totalmente iluminado. Sem presenca. Repouso total.");
  }

  delay(1000);
}

