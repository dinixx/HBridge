#include <HBridge.h>

HBridge motor(9, 10);

void setup()
{
}

void loop()
{
  motor.setDirection(CW);
  for (int i = 0; i <= 255; i++)
  {
    motor.setSpeed(i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--)
  {
    motor.setSpeed(i);
    delay(5);
  }

  motor.setDirection(CCW);
  for (int i = 0; i <= 255; i++)
  {
    motor.setSpeed(i);
    delay(5);
  }
  for (int i = 255; i >= 0; i--)
  {
    motor.setSpeed(i);
    delay(5);
  }
}
