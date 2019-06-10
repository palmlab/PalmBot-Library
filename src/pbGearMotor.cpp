#include "pbGearMotor.h"
#include <Arduino.h>

pbGearMotor::pbGearMotor()
{
    _dir = pbPin();
    _pwm = pbPin();
}


pbGearMotor::pbGearMotor(uint8_t dir, uint8_t pwm)
{
    _dir = pbPin(dir);
    _pwm = pbPin(pwm);
}


void pbGearMotor::Run(uint8_t direction, uint8_t speed)
{
    _dir.DigitalWrite(direction);
    speed = speed > 245 ? 245:speed;
    if (direction == FORWARD_DIRECTION)
    {
        speed = 255-speed;
    }
    _pwm.AnalogeWrite(speed);
    _speed = speed;
    _direction = direction;
}

void pbGearMotor::Stop(void)
{
    _dir.DigitalWrite(LOW);
    _pwm.DigitalWrite(LOW);
    _speed = 0;
}

uint8_t pbGearMotor::getSpeed(void)
{
    return _speed;  
}

uint8_t pbGearMotor::getDirection(void)
{
    return _direction;  
}