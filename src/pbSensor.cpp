#include <Arduino.h>
#include <pbSensor.h>

pbSensor::pbSensor(pbPort port)
{
    _port = port;
}


bool pbSensor::Attach(pbPort port)
{
    _port = port;
}


bool pbSensor::Deattach(void)
{
    _port = pbPort();
}


pbPort pbSensor::getPort()
{
    return _port;
}
