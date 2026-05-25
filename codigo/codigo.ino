int ldr = A0;
int pir = 2;
int led = 13;
int buzzer = 8;

void setup() {

  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Corrige inversão do LDR
  int luz = 1023 - analogRead(ldr);

  int movimento = digitalRead(pir);

  Serial.print("Luminosidade: ");
  Serial.println(luz);

  Serial.print("Movimento: ");
  Serial.println(movimento);

  // Escuro + movimento
  if (luz < 500 && movimento == HIGH) {

    digitalWrite(led, HIGH);

    tone(buzzer, 1000);

    Serial.println("ALERTA: Movimento detectado no escuro!");

  } 
  // Claro + movimento
  else if (luz >= 500 && movimento == HIGH) {

    digitalWrite(led, LOW);

    noTone(buzzer);

    Serial.println("Movimento detectado em ambiente iluminado.");

  } 
  // Sem movimento
  else {

    digitalWrite(led, LOW);

    noTone(buzzer);

    Serial.println("Ambiente seguro.");
  }

  delay(1000);
}
