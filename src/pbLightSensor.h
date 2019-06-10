#ifndef PB_LIGHTSENSOR_H
#define PB_LIGHTSENSOR_H

#include <pbDatatypes.h>
#include <pbSensor.h>
#include <pbPin.h>



class pbLightSensor: public pbSensor
{
public:
  pbLightSensor();
  pbLightSensor(pbPort port);
  pbLightSensor(uint8_t pin);
  int16_t Read(void);

protected:
  pbPin _pin;
};
#endif