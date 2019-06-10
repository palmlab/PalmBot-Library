#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include <pbDatatypes.h>


class CmdParser
{
public:
  CmdParser(void);
  void Reset(void);
  bool Parse(uint8_t byte);
  uint8_t Size;
  uint8_t Data[51];

protected:
  uint8_t _token = 0;
  uint8_t _recv_size = 0;
};
#endif
