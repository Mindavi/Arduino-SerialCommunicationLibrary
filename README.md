# Arduino-SerialCommunicationLibrary
This library can be used for Serial communication between, for instance, an Arduino and a pc.

To use this library, copy the cpp and h file to the folder where your ino file is in.

###Usage
To initialize the library, use: `SerialCommunication sercom = SerialCommunication(&Serial);`
To check if a valid command has come through, use `sercom.update()`.
This command will return true if a valid command has come through, or a too long command has come through.
After this, call `sercom.getCommand()`. 
This will return `LENGTH_ERROR` when the command was too long, and else the command that was sent through Serial.
To change the max command length, change the value that is defined as `MAX_COMMAND_LENGTH`.
By default, the begin of a command is marked by a `%`, and the end is marked by a `$`.
