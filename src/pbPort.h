#ifndef PB_PORT_H_
#define PB_PORT_H_

#include <pbPin.h>




class pbPort
{

public:
  pbPort(void);
  pbPort(uint8_t pin1, uint8_t pin2);
  void reset(void);
  pbPin Pin1;
  pbPin Pin2;

protected:
  

};
#endif // MEPORT_H_
