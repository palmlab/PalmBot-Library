#include <Arduino.h>
#include <pbUltrasonic.h>


#ifdef NRF51
#define DITSTANCE_SCALE 1.3
#else
#define DITSTANCE_SCALE 1
#endif


pbUltrasonic::pbUltrasonic(pbPort port) : pbSensor(port)
{
    //_port = port;

  // Assign triPIN
  pinMode(_port.Pin1.getPin(), OUTPUT);
  // Assign echoPIN
  pinMode(_port.Pin2.getPin(), INPUT);
}

uint32_t pbUltrasonic::Measure(void)
{
  uint32_t duration;
 
  _port.Pin1.DigitalWrite(LOW);
  delayMicroseconds(20);
  _port.Pin1.DigitalWrite(HIGH);
  delayMicroseconds(12);
  _port.Pin1.DigitalWrite(LOW);
  delayMicroseconds(20);

  uint32_t epin = _port.Pin2.getPin();
#ifdef NRF51
  epin = g_ADigitalPinMap[_port.Pin2.getPin()];
#endif
  duration = (uint32_t) pulseIn(epin, HIGH, timeout);
  duration /= (58 * DITSTANCE_SCALE);
 
  return duration;
}
