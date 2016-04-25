#include "SerialCommunication.h"

SerialCommunication communication = SerialCommunication(&Serial);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (communication.update()) {
    Serial.println(communication.getCommand());
  }
}

