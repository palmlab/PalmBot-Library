#include <Arduino.h>
#include <pbButton.h>


pbButton::pbButton(pbPort port) : pbSensor(port)
{
}

pbButton::pbButton(): pbSensor(pbPort())
{
}

pbButton::pbButton(uint8_t pin) : pbSensor(pbPort(pin,pin))
{
}

bool pbButton::IsPressed(void)
{
  return !(_port.Pin2.DigitalRead());
}