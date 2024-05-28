const int ledPinsBranco[] = {23, 19, 22, 21};
const int ledPinsColoridos[] = {18, 5, 17};
const int butao = 15;
const int ledVermelho = 2;
const int ledVerde = 16;
const int numLedsBranco = sizeof(ledPinsBranco) / sizeof(ledPinsBranco[0]);
const int numLedsColoridos = sizeof(ledPinsColoridos) / sizeof(ledPinsColoridos[0]);
const int espera = 500;

void semaforo() {
  for (int i = 0; i < numLedsBranco; i++) {
    digitalWrite(ledPinsBranco[i], HIGH);
    delay(espera);
  }
  
  for (int i = 0; i < numLedsColoridos; i++) {
    digitalWrite(ledPinsColoridos[i], HIGH);
    delay(espera);
    digitalWrite(ledPinsColoridos[i], LOW);
    digitalWrite(ledPinsColoridos[i+1], HIGH);
    delay(espera);
  }

  digitalWrite(ledVerde, HIGH);
  delay(espera);
  digitalWrite(ledPinsBranco[0], LOW);
  digitalWrite(ledPinsBranco[1], LOW);
  digitalWrite(ledPinsBranco[2], LOW);
  digitalWrite(ledPinsBranco[3], LOW);
}

void setup() {
  for (int i = 0; i < numLedsBranco; i++) {
    pinMode(ledPinsBranco[i], OUTPUT);
  }

  for (int i = 0; i < numLedsColoridos; i++) {
    pinMode(ledPinsColoridos[i], OUTPUT);
  }

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(butao, INPUT_PULLUP);

  semaforo();
}

void loop() {
  if(digitalRead(butao) == LOW){
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    delay(espera);
    digitalWrite(ledVermelho, LOW);
    delay(espera);
    semaforo();
  }
  
}
