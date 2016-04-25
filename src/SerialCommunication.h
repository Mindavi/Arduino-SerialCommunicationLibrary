#ifndef SerialCommunication_h
#define SerialCommunication_h
#include <Arduino.h>

#define BEGINDELIMITER '%'
#define ENDDELIMITER '$'
#define MAX_COMMAND_LENGTH 20

enum class Communication { WaitForStart, Receiving };


class SerialCommunication {
  private:
    String data;
    char incomingChar;
    String receivedString;
    Stream* deviceToCommunicateWith;
    Communication state;
    String lastCommand;
    void reset();
  public:
    SerialCommunication(Stream *theStream);
    String getCommand();
    bool update();
};

#endif