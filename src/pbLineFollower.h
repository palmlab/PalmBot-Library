#ifndef PB_LINE_FOLLOWER_H
#define PB_LINE_FOLLOWER_H

#include <pbDatatypes.h>
#include <pbSensor.h>



class pbLineFollower: public pbSensor
{
public:
  pbLineFollower(pbPort port);
  uint8_t readSensors(void);
  bool ReadSensor1(void);
  bool ReadSensor2(void);

private:
  
};

#endif 

