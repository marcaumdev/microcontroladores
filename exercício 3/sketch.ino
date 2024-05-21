const int ledPins[] = {16, 19, 22};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
const int espera = 500;

void setup() {
  for(int i = 0; i < numLeds; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int randomX = random(numLeds);
  digitalWrite(ledPins[randomX], HIGH);
  delay(espera);
  digitalWrite(ledPins[randomX], LOW);
  delay(espera);
}
