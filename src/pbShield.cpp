#include "pbShield.h"


pbPort pbShield::getPort(uint8_t port)
{
	return (port==1)? Port1 :
           (port==2)? Port2	:
           (port==3)? Port3	:
           (port==4)? Port4	: Port1;
}	

void pbShield::RunOneMotor(uint8_t motorPort, int16_t speed)
{
    if(motorPort ==0){ // left
        LMotor.Run(speed>0? FORWARD_DIRECTION:BACKWARD_DIRECTION, abs(speed));
    } else if(motorPort ==1){ // right
        RMotor.Run(speed>0? FORWARD_DIRECTION:BACKWARD_DIRECTION, abs(speed));
    }
}	   
		   
void pbShield::MoveForward(uint8_t speed)
{
    LMotor.Run(FORWARD_DIRECTION, speed);
    RMotor.Run(BACKWARD_DIRECTION, speed);
}

void pbShield::MoveBackward(uint8_t speed)
{
    LMotor.Run(BACKWARD_DIRECTION, speed);
    RMotor.Run(FORWARD_DIRECTION, speed);
}

void pbShield::Stop(void)
{
    LMotor.Stop();
    RMotor.Stop();
}

void pbShield::TurnLeft(uint8_t speed)
{
    LMotor.Run(BACKWARD_DIRECTION, speed);
    RMotor.Run(BACKWARD_DIRECTION, speed);
}

void pbShield::TurnRight(uint8_t speed)
{
    LMotor.Run(FORWARD_DIRECTION, speed);
    RMotor.Run(FORWARD_DIRECTION, speed);
}

/*
void pbShield::TurnLeft(void)
{
    uint8_t lSpeed = LMotor.getSpeed();
    uint8_t rSpeed = LMotor.getSpeed();
    uint16_t lDir = LMotor.getDirection();
    uint16_t rDir = LMotor.getDirection();

    LMotor.Stop();
    RMotor.Run(FORWARD_DIRECTION, 100);
    delay(1000);
    RMotor.Stop();
    if (lSpeed != 0)
    {
       LMotor.Run(lDir, lSpeed);
    }
    if (rSpeed != 0)
    {
       RMotor.Run(rDir, rSpeed);
    }
}

void pbShield::TurnRight(void)
{
    uint8_t lSpeed = LMotor.getSpeed();
    uint8_t rSpeed = LMotor.getSpeed();
    uint16_t lDir = LMotor.getDirection();
    uint16_t rDir = LMotor.getDirection();

    RMotor.Stop();
    LMotor.Run(FORWARD_DIRECTION, 100);
    delay(1000);
    LMotor.Stop();
    if (lSpeed != 0)
    {
       LMotor.Run(lDir, lSpeed);
    }
    if (rSpeed != 0)
    {
       RMotor.Run(rDir, rSpeed);
    }
}
*/

void pbShield::PlayTone(uint16_t frequency, uint32_t duration)
{
	Buzzer.Tone(frequency, duration);
}

void pbShield::TurnLED_ON()
{
    LED.On();
}

void pbShield::TurnLED_OFF()
{
    LED.Off();
}

void pbShield::TurnLED(uint8_t on_off)
{
	if(on_off)
		LED.On();
	else
		LED.Off();
}

bool pbShield::ButtonPressed()
{
    return Button.IsPressed();
}

int16_t pbShield::LightSense(uint8_t port)
{
	if(port > 4)
		return LightSensor.Read();
	else {
		/*
		pbLightSensor ls = (port==1)? pbLightSensor(Port1): 
						   (port==2)? pbLightSensor(Port2): 
						   (port==3)? pbLightSensor(Port3):
						   (port==4)? pbLightSensor(Port4): pbLightSensor(Port4);
		*/
		
		pbLightSensor ls = pbLightSensor(getPort(port));
						   
		return ls.Read();
	}
}