#ifndef PB_SERVO_MOTOR_H
#define PB_SERVO_MOTOR_H

#include <pbDatatypes.h>
#include <pbSensor.h>
#include "extra\Servo.h"


class pbServoMotor
{
public:
  pbServoMotor();
  pbServoMotor(pbPort port);

  //void Attach(uint8_t slot);
  bool Set(uint8_t slot, uint8_t angle);
  bool Set(pbPort port, uint8_t slot, uint8_t angle);


protected:
  pbPort _port;
  uint8_t _angle;
  Servo _servo;
};
#endif

