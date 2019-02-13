#include <Arduino.h>
#include "HBridge.h"

HBridge::HBridge(int pwmA, int pwmB)
{
  _pwmA = pwmA;
  _pwmB = pwmB;
  _direction = CW;
  _speed = 0;
  //analogWrite(_pwmA, 0);
  pinMode(_pwmA, OUTPUT);
  digitalWrite(_pwmA, LOW);
  //analogWrite(_pwmB, 0);
  pinMode(_pwmB, OUTPUT);
  digitalWrite(_pwmB, LOW);
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
    setSpeed(getSpeed());
  }
}

void HBridge::invertDirection()
{
  if (CW == _direction)
  {
    setDirection(CCW);
  }
  else
  {
    setDirection(CW);
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
      //analogWrite(_pwmB, 0);
      pinMode(_pwmB, OUTPUT);
      digitalWrite(_pwmB, LOW);
      analogWrite(_pwmA, _speed);
    }
    else
    {
      //analogWrite(_pwmA, 0);
      pinMode(_pwmA, OUTPUT);
      digitalWrite(_pwmA, LOW);
      analogWrite(_pwmB, _speed);
    }
  }
}
