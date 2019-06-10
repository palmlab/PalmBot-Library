#include "CmdParser.h"
#include <Arduino.h>

#define SOF1        0
#define SOF2        1
#define SIZE        2
#define DATA        3

CmdParser::CmdParser()
{

}

void CmdParser::Reset()
{
    _token = SOF1;
    Size = 0;

}

bool CmdParser::Parse(uint8_t byte)
{
    uint8_t next_token = 0;
    bool result = FALSE;

    //Serial.println(_token);

    switch (_token)
    {
        case SOF1:
            _recv_size = 0;
            Size = 0;
            next_token = byte == 0xFF? SOF2:SOF1;
            break;

        case SOF2:
            _recv_size = 0;
            Size = 0;
            next_token = byte == 0x55? SIZE:SOF1;
            break;

        case SIZE:
            _recv_size = byte;
            next_token = _recv_size < 51? DATA:SOF1;
            break;

        case DATA:
            if (Size < _recv_size)
            {
                Data[Size] = byte;
                Size++;
            }
            result = Size >= _recv_size? TRUE: FALSE;
            next_token = result? SOF1:DATA;
            break;
    }
    _token = next_token;
    return result;
}

