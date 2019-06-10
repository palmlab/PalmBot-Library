#include "pbPort.h"


pbPort::pbPort(void)
{
  //Pin1 = new pbPin();
  //Pin2 = new pbPin();
}


pbPort::pbPort(uint8_t pin1, uint8_t pin2)
{
  Pin1 = pbPin(pin1);
  Pin2 = pbPin(pin2);
}


void pbPort::reset(void)
{
  
}






