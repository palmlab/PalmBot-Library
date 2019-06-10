#ifndef SERIAL_HANDLER_H
#define SERIAL_HANDLER_H

#include <pbDatatypes.h>
#include <CmdParser.h>
#include <CmdDevices.h>


typedef struct
{
  uint8_t device;
  union
  {
    CmdPort ultrasonic;
    CmdPortSlot temprature;
    CmdPort light;
    CmdPort sound;
    CmdPort potentionmeter;
    CmdJoystick joystick;
    CmdPort linefollower;
    CmdPinValue digital;
    CmdPin analog;
    CmdPinValue pwm;
    CmdMotor motor;
    CmdServo servo;
    CmdBuzzer tone;
	CmdLED led;
	CmdButton button;
  };
} CmdRequest;

typedef struct 
{
  uint8_t type;
  union
  {
    uint16_t _short;
    float    _float;
  };
} CmdResponse;

typedef struct 
{
  uint8_t id;
  uint8_t command;
  CmdRequest details;
} CmdPacket;




class CmdHandler
{
public:
  CmdHandler();
  bool Handle(void);
  bool (*OnRun)(CmdRequest* req);
  bool (*OnGet)(CmdRequest* req, CmdResponse* resp);

private:
  CmdParser _parser;
};

#endif 

