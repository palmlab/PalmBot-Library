#ifndef PB_ULTRASONIC_H
#define PB_ULTRASONIC_H

#include <pbDatatypes.h>
#include <pbSensor.h>



class pbUltrasonic: public pbSensor
{
public:
  pbUltrasonic(pbPort port);
  //double distanceCm(uint16_t = 400);
  //double distanceInch(uint16_t = 180);
  uint32_t Measure(void);

private:
  //pbPort _port;
  uint32_t timeout = 30000;
};

#endif 

