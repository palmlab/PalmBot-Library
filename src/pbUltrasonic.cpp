#include <Arduino.h>
#include <pbUltrasonic.h>



pbUltrasonic::pbUltrasonic(pbPort port) : pbSensor(port)
{
    //_port = port;
}

uint32_t pbUltrasonic::Measure(void)
{
  uint32_t duration;
 
  _port.Pin1.DigitalWrite(LOW);
  _port.Pin2.DigitalWrite(LOW);
  delayMicroseconds(2);
  _port.Pin1.DigitalWrite(HIGH);
  _port.Pin2.DigitalWrite(HIGH);
  delayMicroseconds(10);
  _port.Pin1.DigitalWrite(LOW);
  _port.Pin2.DigitalWrite(LOW);
  pinMode(_port.Pin2.getPin(), INPUT);
  duration = (uint32_t) pulseIn(_port.Pin2.getPin(), HIGH, timeout);
  duration /= 58;
 
  return duration;
}