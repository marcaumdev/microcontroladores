const int ledPins[] = {16, 19, 22};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
const int espera = 1500;

void setup() {
  for(int i = 0; i < numLeds; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < numLeds; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(espera);
    digitalWrite(ledPins[i], LOW);
    delay(espera);
  }
}
