#ifndef PB_BUTTON_H
#define PB_BUTTON_H

#include <pbDatatypes.h>
#include <pbSensor.h>
#include <pbPin.h>



class pbButton: public pbSensor
{
public:
  pbButton();
  pbButton(pbPort port);
  pbButton(uint8_t pin);
  bool IsPressed(void);

protected:
  pbPin _pin;
};
#endif