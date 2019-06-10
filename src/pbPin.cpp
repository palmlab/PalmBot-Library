#include "pbPin.h"


pbPin::pbPin(void)
{
  _pin = 1;
}

pbPin::pbPin(uint8_t pin)
{
  _pin = pin;
}


bool pbPin::DigitalRead(uint8_t mode)
{
  bool val;
  pinMode(_pin, mode);
  val = digitalRead(_pin);
  return(val);
}


void pbPin::DigitalWrite(bool value)
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, value);
}


int16_t pbPin::AnalogeRead(void)
{
  int16_t val;
  pinMode(_pin, INPUT);
  val = analogRead(_pin);
  return(val);
}


void pbPin::AnalogeWrite(int16_t value)
{
  analogWrite(_pin, value);
}

uint8_t pbPin::getPin(void)
{
  return _pin;
}



