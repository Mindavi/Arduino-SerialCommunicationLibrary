#include <SerialCommunication.h>

//the constructor takes three arguments, the two last arguments are the begin- and the enddelimiter
//the last two arguments are optional, by default these are set to '%' and '$'
SerialCommunication communication;

void setup() {
  //you have to initialise the library
  communication.begin(&Serial, '!', '&');
  Serial.begin(9600);
}

void loop() {
  //first check for an update, if there is one then check the command
  //a valid command could be !hello&, which will translate to hello because the begindelimiters are thrown away
  if (communication.update()) {
    Serial.println(communication.getCommand());
  }
}

