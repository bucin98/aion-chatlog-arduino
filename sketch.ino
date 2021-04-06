#include <Keyboard.h>

void setup()
{
  Keyboard.begin();
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    String KeyboardInitialization = Serial.readStringUntil('\0');
    int keyboard = KeyboardInitialization.toInt();

    
    Keyboard.write(keyboard);
  }
}
