#include <Arduino.h>
#include <pbLineFollower.h>



pbLineFollower::pbLineFollower(pbPort port) : pbSensor(port)
{
    //_port = port;
}

/**
 * \par Function
 *   readSensors
 * \par Description
 *   Get the sensors state.
 * \par Output
 *   None
 * \return
 *   (0x00)-S1_IN_S2_IN:   sensor1 and sensor2 are both inside of black line \n
 *   (0x01)-S1_IN_S2_OUT:  sensor1 is inside of black line and sensor2 is outside of black line \n
 *   (0x02)-S1_OUT_S2_IN:  sensor1 is outside of black line and sensor2 is inside of black line \n
 *   (0x03)-S1_OUT_S2_OUT: sensor1 and sensor2 are both outside of black line
 * \par Others
 *   None
 */
uint8_t pbLineFollower::readSensors(void)
{
  uint8_t state;

  //LeftSensor
  bool s1State = _port.Pin1.DigitalRead();
  //RightSensor
  bool s2State = _port.Pin2.DigitalRead();

  state = ( (1 & s1State) << 1) | s2State;
  return(state);
}

// Naif: I will assume in Scratch extension that this is the LeftSensor
bool pbLineFollower::ReadSensor1(void)
{
  return _port.Pin1.DigitalRead();
}

// Naif: I will assume in Scratch extension that this is the RightSensor
bool pbLineFollower::ReadSensor2(void)
{
  return _port.Pin2.DigitalRead();
}