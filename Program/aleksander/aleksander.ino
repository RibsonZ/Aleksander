#include <Servo.h>

#define SERV 9
#define SENS 12

Servo Sprayer;

int pos = 180;

void setup() {
  Sprayer.attach(SERV);
  Sprayer.write(pos);
  pinMode(SENS,INPUT);
}

void loop() {
  if (digitalRead(SENS) == LOW) {
    squeeze();
    delay(200);
    relax();
    delay(400);
  }
}

void squeeze() {
  for (pos = 180; pos >= 30; pos -= 1) {
    Sprayer.write(pos);
    delay(5);
  }
}

void relax() {
  for (pos = 30; pos <= 180; pos += 1) {
    Sprayer.write(pos);
    delay(5);
  }
}
