#define leds 4
#define butao 15

int roxinhu[leds] = {0, 2, 16, 5};
int rozenha[leds] = {19, 21, 22, 23};
int x = 0;

void setup() {
 for(int i = 0; i < leds; i++){
  pinMode(roxinhu[i], OUTPUT);
  pinMode(rozenha[i], OUTPUT);
 }
 pinMode(butao, INPUT_PULLUP);
}

void loop() {
  while(digitalRead(butao) == HIGH){
    while(x < leds){
      digitalWrite(roxinhu[x], HIGH);
      digitalWrite(rozenha[leds - 1 - x], HIGH);
      delay(250);
      digitalWrite(roxinhu[x], LOW);
      digitalWrite(rozenha[leds - 1 - x], LOW);
      x++;
    }
    x = 0;
  }

  while(x < leds){
      digitalWrite(roxinhu[x], HIGH);
      digitalWrite(rozenha[x], HIGH);
      delay(250);
      digitalWrite(roxinhu[x], LOW);
      digitalWrite(rozenha[x], LOW);
      x++;
    }
    x = 0;
}
