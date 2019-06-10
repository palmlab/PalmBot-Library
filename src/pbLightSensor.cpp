#include <Arduino.h>
#include <pbLightSensor.h>


pbLightSensor::pbLightSensor(pbPort port) : pbSensor(port)
{
}

pbLightSensor::pbLightSensor(): pbSensor(pbPort())
{
}

pbLightSensor::pbLightSensor(uint8_t pin) : pbSensor(pbPort(pin,pin))
{
}

int16_t pbLightSensor::Read(void)
{
  return _port.Pin2.AnalogeRead();
}