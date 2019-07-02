#ifndef PB_SHIELD_H_
#define PB_SHIELD_H_

#include <pbPort.h>
#include <pbGearMotor.h>
#include <pbBuzzer.h>
#include <pbLED.h>
#include <pbButton.h>
#include <pbLightSensor.h>

class pbShield
{

public:

// Arduino pins
#if defined(ARDUINO_ARCH_AVR)
  pbPort Port1 = pbPort(11,12);
  pbPort Port2 = pbPort(9,10);
  pbPort Port3 = pbPort(A2,A3);
  pbPort Port4 = pbPort(A0,A1);
  pbPort servoPort = pbPort(7,7);
  pbPort Port0 = servoPort;
  pbBuzzer Buzzer = pbBuzzer(8);
  pbLED LED = pbLED(13);
  pbButton Button = pbButton(3) ;
  pbLightSensor LightSensor = pbLightSensor(A4);
  pbGearMotor LMotor = pbGearMotor(2,5);
  pbGearMotor RMotor = pbGearMotor(4,6);

// Microbit pins
#elif defined NRF51
  pbPort Port1 = pbPort(10,14);
  pbPort Port2 = pbPort(15,16);
  pbPort Port3 = pbPort(0,1);
  pbPort Port4 = pbPort(2,4);
  pbPort servoPort = pbPort(7,7);
  pbPort Port0 = servoPort;
  pbBuzzer Buzzer = pbBuzzer(12);
  pbLED LED = pbLED(13);
  pbButton Button = pbButton(11) ;
  pbLightSensor LightSensor = pbLightSensor(3);
  pbGearMotor LMotor = pbGearMotor(6,7);
  pbGearMotor RMotor = pbGearMotor(8,9);
#else
 #error "This library only supports boards with an AVR or NRF1 processor."
#endif

  pbPort getPort(uint8_t port);
  void RunOneMotor(uint8_t motorPort, int16_t speed);
  void MoveForward(uint8_t Speed);
  void MoveBackward(uint8_t Speed);
  void Stop(void);
  void TurnLeft(uint8_t Speed);
  void TurnRight(uint8_t Speed);
  void PlayTone(uint16_t frequency, uint32_t duration);
  void TurnLED(uint8_t on_off);
  bool ButtonPressed(void);
  int16_t LightSense(uint8_t port);

};

#endif
