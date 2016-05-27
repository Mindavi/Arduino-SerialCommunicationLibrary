#include <SerialCommunication.h>
#include <SoftwareSerial.h>

SoftwareSerial swser(10,11);

//the constructor takes three arguments, the two last arguments are the begin- and the enddelimiter
//the last two arguments are optional, by default these are set to '%' and '$'
SerialCommunication communication;

void setup() {
  // initialise object
  communication.begin(&swser);
  // initial serial for debugging
  Serial.begin(9600);
  // initialise serial communication
  swser.begin(9600);
}

void loop() {
  //first check for an update, if there is one then check the command
  //a valid command could be %hello$
  if (communication.update()) {
    Serial.println(communication.getCommand());
  }
}

