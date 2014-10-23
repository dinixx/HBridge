#include <Arduino.h>
#include "HBridge.h"

HBridge::HBridge(int pwmA, int pwmB)
{
  _pwmA = pwmA;
  _pwmB = pwmB;
  _direction = CW;
  _speed = 0;
  analogWrite(_pwmA, 0);
  analogWrite(_pwmB, 0);
}

int HBridge::getDirection()
{
  return _direction;
}

void HBridge::setDirection(int direction)
{
  if (CW == direction || CCW == direction)
  {
    _direction = direction;
  }
}

int HBridge::getSpeed()
{
  return _speed;
}

void HBridge::setSpeed(int speed)
{
  if (0 <= speed && 255 >= speed)
  {
    _speed = speed;

    if (CW == _direction)
    {
      analogWrite(_pwmA, _speed);
      analogWrite(_pwmB, 0);
    }
    else
    {
      analogWrite(_pwmA, 0);
      analogWrite(_pwmB, _speed);
    }
  }
}

void HBridge::invertDirection()
{
  if (CW == _direction)
  {
    _direction = CCW;
  }
  else
  {
    _direction = CW;
  }
}
