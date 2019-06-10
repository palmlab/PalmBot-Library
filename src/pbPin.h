#ifndef PB_PIN_H_
#define PB_PIN_H_

#include <pbDatatypes.h>
#include <Arduino.h>



class pbPin
{

public:

  pbPin(void);
  pbPin(uint8_t pin);


  bool DigitalRead(uint8_t mode = INPUT);
  void DigitalWrite(bool value);
  int16_t AnalogeRead(void);
  void AnalogeWrite(int16_t value);
  uint8_t getPin(void);

 

protected:
  uint8_t _pin;

};
#endif
