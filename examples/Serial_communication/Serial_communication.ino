#include <SerialCommunication.h>

//the constructor takes three arguments, the two last arguments are the begin- and the enddelimiter
//the last two arguments are optional, by default these are set to '%' and '$'
SerialCommunication communication = SerialCommunication(&Serial, '!', '&');

void setup() {
  Serial.begin(9600);
}

void loop() {
  //first check for an update, if there is one then check the command
  //a valid command could be !hello&
  if (communication.update()) {
    Serial.println(communication.getCommand());
  }
}

