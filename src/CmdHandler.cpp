#include <Arduino.h>
#include <CmdHandler.h>


CmdHandler::CmdHandler(void)
{
}

static void SendData(CmdResponse * data)
{
    switch (data->type)
    {
        case FLOAT_DATATYPE:
            Serial.write((uint8_t)data->type);
            Serial.write(((uint8_t*)&data->_float)[0]);
            Serial.write(((uint8_t*)&data->_float)[1]);
            Serial.write(((uint8_t*)&data->_float)[2]);
            Serial.write(((uint8_t*)&data->_float)[3]);
            break;
    }
}

bool CmdHandler::Handle(void)
{
    bool result = false;
    CmdResponse resp;
    
    while (Serial.available()>0)
    {
        if (_parser.Parse(Serial.read()))
        {
            CmdPacket* req = (CmdPacket*)_parser.Data;
            switch (req->command)
            {
                case 0x01: //Get
                    if (OnGet != NULL && OnGet(&req->details, &resp ))
                    {
                        Serial.write((uint8_t)0xff);
                        Serial.write((uint8_t)0x55);
                        Serial.write((uint8_t)0x00);
                        SendData(&resp);
                        Serial.write((uint8_t)0x0d);
                        Serial.write((uint8_t)0x0a);
                    }
                    break;

                case 0x02: //RUN;
                    if (OnRun != NULL && OnRun(&req->details))
                    {
                        Serial.write((uint8_t)0xff);
                        Serial.write((uint8_t)0x55);
                        Serial.write((uint8_t)0x0d);
                        Serial.write((uint8_t)0x0a);
                    }
                    break;

                
            }
        }
    }
    
    return result;
}
