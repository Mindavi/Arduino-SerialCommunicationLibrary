# Arduino-SerialCommunicationLibrary
This library can be used for Serial communication between, for instance, an Arduino and a pc.

To use this library, download the library as zip and unpack it in the libraries folder of the Arduino software. You can also add the library like this: sketch->include library->add .zip library.

###Usage
To initialize the library, use: `SerialCommunication sercom = SerialCommunication();`
After this, call `sercom.begin(Serial)` to create the object with the right stream.
When you have not done this, a call to update will always return false, and a call to getCommand will return `NOT_STARTED_ERROR`.
To check if a valid command has come through, use `sercom.update()`.
This command will return true if a valid command has come through, or a too long command has come through.
After this, call `sercom.getCommand()`. 
This will return `LENGTH_ERROR` when the command was too long, and else the command that was sent through Serial.
To change the max command length, change the value that is defined as `MAX_COMMAND_LENGTH`.
By default, the begin of a command is marked by a `%`, and the end is marked by a `$`.

###Version
This is version 1.0.0