#ifndef PB_GEAR_MOTOR_H
#define PB_GEAR_MOTOR_H

#include <pbDatatypes.h>
#include <pbPin.h>

#define BACKWARD_DIRECTION      0
#define FORWARD_DIRECTION       1

class pbGearMotor
{
public:
  pbGearMotor(void);
  pbGearMotor(uint8_t dir, uint8_t pwm);

  void Run(uint8_t direction, uint8_t speed);
  void Stop(void);
  uint8_t getSpeed(void);
  uint8_t getDirection(void);


protected:
  pbPin _dir;
  pbPin _pwm;
  uint8_t _speed;
  uint8_t _direction;
};
#endif

