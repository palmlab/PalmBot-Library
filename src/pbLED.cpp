#include "pbLED.h"
#include <Arduino.h>

pbLED::pbLED()
{
  _pin = pbPin();
}

pbLED::pbLED(uint8_t pin)
{
  _pin = pbPin(pin);
}

void pbLED::On()
{
     _pin.DigitalWrite(HIGH);
}

void pbLED::Off()
{
     _pin.DigitalWrite(LOW);
}
