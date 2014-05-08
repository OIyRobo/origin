#ifndef BLUETOOTH_H
#define BLUETOOTH_H

const int left = 0;   //====================
const int back = 1;   // Enumerated dir
const int right = 2;  // numbers for sensors
const int front = 3;  //====================
int sonarValue[4]; //Array of sonar values

task SendAck(); //sends acknowledgement request to other nxt, starts ReceiveData() when it receives an ack in return
task LookForAck(); //Searchs for ack request, then starts the SendData() task
task SendSensorData(); //Sends sensor data from ports 1-3
task ReceiveData(); //Reads data sent on bluetooth into the sonarValue A

#include "../lib/Bluetooth.c"

#endif //BLUETOOTH_H
