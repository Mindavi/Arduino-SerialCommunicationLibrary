#include "SerialCommunication.h"
#include <SoftwareSerial.h>

SoftwareSerial swser(10,11);
SerialCommunication communication = SerialCommunication(&swser);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //first check for an update, if there is one then check the command
  if (communication.update()) {
    Serial.println(communication.getCommand());
  }
}

