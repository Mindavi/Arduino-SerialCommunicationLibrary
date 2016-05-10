/*
   class handling the serial communication
   when anything is available, it will check if it is a begindelimiter.
   When it is a begindelimiter, it will clear the receivedstring.
   If it is anything else, it will read it into a buffer, called receivedString

*/
#include "SerialCommunication.h"


SerialCommunication::SerialCommunication(Stream *theStream, char beginDelimiter, char endDelimiter) {
  this->beginDelimiter = beginDelimiter;
  this->endDelimiter = endDelimiter;
  this->receivedString = "";
  this->incomingChar = '\0';
  this->data = "";
  this->state = Communication::WaitForStart;
  this->lastCommand = "";
  this->deviceToCommunicateWith = theStream;
}

String SerialCommunication::getCommand() {
  return this->lastCommand;
}

bool SerialCommunication::update() {
  if (deviceToCommunicateWith->available() > 0) {
    this->incomingChar = deviceToCommunicateWith->read();
    switch (state) {
      case Communication::WaitForStart:
        if (this->incomingChar == this->beginDelimiter) {
          this->receivedString = "";
          this->state = Communication::Receiving;
        }
        break;
      case Communication::Receiving:
        if (this->incomingChar == this->endDelimiter) {
          this->lastCommand = this->receivedString;
          reset();
          return true;
        } else {
          this->receivedString += this->incomingChar;
        }

        if (this->receivedString.length() > MAX_COMMAND_LENGTH) {
          this->lastCommand = "LENGTH_ERROR";
          reset();
          return true;
        }
        break;
    }
  }
  return false;
}

void SerialCommunication::reset() {
  this->receivedString = "";
  this->state = Communication::WaitForStart;
}

