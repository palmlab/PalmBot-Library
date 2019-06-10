#ifndef CMD_DEVICES_H
#define CMD_DEVICES_H

#include <pbDatatypes.h>


enum device_cmds
{
  ULTRASONIC_CMD = 0x01,
  TEMPERATURE_CMD = 0x02,
  LIGHT_CMD = 0x03,
  POTENTIONMETER_CMD = 0x04,
  JOYSTICK_CMD = 0x05,
  LED_CMD = 0x06,
  SOUND_CMD = 0x07,
  MOTOR_CMD = 0x0A,
  SERVO_CMD = 0x0B,
  ENCODER_CMD = 0x0C,
  LINEFOLLOWER_CMD = 0x11,
  BUTTON_CMD = 0x16,
  DIGITAL_CMD = 0x1E,
  ANALOG_CMD = 0x1F,
  PWM_CMD = 0x20,
  TONE_CMD = 0x22,
  LEDMATRIX_CMD = 0x29,
  TIMER_CMD = 0x32,
};


enum cmd_datatypes
{
  FLOAT_DATATYPE = 0x02,
};


typedef struct 
{
  uint8_t pin;
} CmdPin;

typedef struct 
{
  uint8_t pin;
  uint8_t value;
} CmdPinValue;

typedef struct 
{
  uint8_t port;
} CmdPort;

typedef struct 
{
  uint8_t port;
  uint8_t slot;
} CmdPortSlot;

typedef struct 
{
  uint8_t port; // port=0 => Left Motor,, port=1 => Right Motor.
  int16_t speed;
} CmdMotor;

typedef struct 
{
  int16_t lspeed;
  int16_t rspeed;
} CmdJoystick;

typedef struct 
{
  uint8_t port;
  uint8_t slot;
  uint8_t angle;
} CmdServo;


typedef struct 
{
  uint16_t freq;
  uint16_t duration;
} CmdBuzzer;

typedef struct 
{
  uint8_t on_off;
} CmdLED;

typedef struct 
{
  uint8_t status;
} CmdButton;



#endif