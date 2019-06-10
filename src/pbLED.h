#ifndef PB_LED_H
#define PB_LED_H

#include <pbPin.h>

class pbLED
{
public:
  pbLED();
  pbLED(uint8_t pin);
  void On();
  void Off();

protected:
  pbPin _pin;
};
#endif