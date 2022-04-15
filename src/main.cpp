#include <Arduino.h>

const byte KEY_ENTER = 0x0D;

void setup()
{
  Serial.begin(115200);
  pinMode(D4, INPUT);
}

int LAST_VALUE = 0x0;

void loop()
{
  byte pin = digitalRead(D4);

  if (pin == LOW && LAST_VALUE == HIGH) {
    Serial.write(KEY_ENTER);
  }

  LAST_VALUE = pin;
  delay(50);
}