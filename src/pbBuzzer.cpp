#include "pbBuzzer.h"
#include <Arduino.h>

pbBuzzer::pbBuzzer()
{
  _pin = pbPin();
}

pbBuzzer::pbBuzzer(uint8_t pin)
{
  _pin = pbPin(pin);
}


void pbBuzzer::Tone(uint16_t frequency, uint32_t duration)
{
  int period = 1000000L / frequency;
  int pulse = period / 2;
  for (long i = 0; i < duration * 1000L; i += period) 
  {
    _pin.DigitalWrite(HIGH);
    delayMicroseconds(pulse);
    _pin.DigitalWrite(LOW);
    delayMicroseconds(pulse);
  }
}

