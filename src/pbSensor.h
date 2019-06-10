#ifndef PB_SENSOR_H
#define PB_SENSOR_H

#include <pbDatatypes.h>
#include <pbPort.h>



class pbSensor
{
public:
  pbSensor(pbPort port);
  bool Attach(pbPort port);
  bool Deattach(void);
  pbPort getPort(void);
  

protected:
  pbPort _port;
  
};

#endif 

