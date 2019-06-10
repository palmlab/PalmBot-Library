#ifndef PB_BUZZER_H
#define PB_BUZZER_H

#include <pbDatatypes.h>
#include <pbPin.h>



class pbBuzzer
{
public:
  pbBuzzer();
  pbBuzzer(uint8_t pin);
  void Tone(uint16_t frequency, uint32_t duration);

protected:
  pbPin _pin;
};
#endif
