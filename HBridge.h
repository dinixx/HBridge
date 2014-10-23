#ifndef HBridge_h
#define HBridge_h

#define CW  0
#define CCW 255

class HBridge
{
public:
  HBridge(int pwmA, int pwmB);

  int getDirection();
  void setDirection(int direction);

  int getSpeed();
  void setSpeed(int speed);

  void invertDirection();

private:
  int _pwmA;
  int _pwmB;
  int _direction;
  int _speed;
};

#endif
