#define qtd_led 5
#define butao 15
#define ledv 2

int pinosLeds[qtd_led] = {0, 16, 5, 19, 21};

void setup() {
  for(int i = 0; i < qtd_led; i++){
    pinMode(pinosLeds[i], OUTPUT);
  }
  pinMode(ledv, OUTPUT);
  pinMode(butao, INPUT_PULLUP);

}

void loop() {
  while(digitalRead(butao) == HIGH){
    digitalWrite(ledv, HIGH);
  }
  for (int i = 0; i < qtd_led; i++){
    digitalWrite(ledv, LOW);
    digitalWrite(pinosLeds[i], HIGH);
    delay(500);
    digitalWrite(pinosLeds[i], LOW);
  }
}
