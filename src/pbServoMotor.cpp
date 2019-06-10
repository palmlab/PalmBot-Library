#include <Arduino.h>
#include <pbServoMotor.h>

pbServoMotor::pbServoMotor() 
{
	_port = pbPort();
}

pbServoMotor::pbServoMotor(pbPort port) 
{
	_port = port;
}

bool pbServoMotor::Set(pbPort port, uint8_t slot, uint8_t angle)
{
    bool result = false;

    _servo.attach(slot == 2? port.Pin2.getPin():port.Pin1.getPin());

	angle = (angle == 0)? 20 : angle;
	angle = (angle == 180)? 166 : angle;
    
	//Naif: This will attach the servo every time we send command,, maybe separate attach and write functions?
	//		Also, this always limit the use of only "Pin1" on the selected port.
    //_servo.attach(_port.Pin1.getPin());
    if (angle > 0 && angle <= 180)
    {
        _angle = angle;
        _servo.write(angle);
        result = true;
    }
    
    return result;
}


bool pbServoMotor::Set(uint8_t slot, uint8_t angle)
{
    bool result = false;

    _servo.attach(slot == 2?_port.Pin2.getPin():_port.Pin1.getPin());

	angle = (angle == 0)? 20 : angle;
	angle = (angle == 180)? 166 : angle;
    
	//Naif: This will attach the servo every time we send command,, maybe separate attach and write functions?
	//		Also, this always limit the use of only "Pin1" on the selected port.
    //_servo.attach(_port.Pin1.getPin());
    if (angle > 0 && angle <= 180)
    {
        _angle = angle;
        _servo.write(angle);
        result = true;
    }
    
    return result;
}
