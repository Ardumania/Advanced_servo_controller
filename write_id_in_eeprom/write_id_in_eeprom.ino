/*
 * EEPROM Write for Advanced Servo Controller
 * by Jose Manuel Escuder
 * ver 0.1 February 23th, 2017
 * License (CC)BY-NC-SA
 * 
 * This firmware must be uploaded to the module using a ArduinoISP
 * or a Arduino UNO as ISP programmer.
 * In the Tools menu select "ATiny25/45/85" as board, then select 
 * "ATtiny85" as processor and at last select "External 16MHz" as clock
 * 
 * To upload this program select "Upload using programmer" in the Program menu.
 * Be sure you have the right programmer selected in the Tools menu.
 * 
 * This program store the number 10 into the EEPROM in 
 * position 0. That number will be the id of this device.
 * If you want to save another id just modify the value in
 * line 28.
 * 
 * Once work is done you can see a blink in the servo pin
 * if connect a LED between it and GND
 */

#include <EEPROM.h>

void setup(){
  
  pinMode(0, OUTPUT);
  // Save number 10 (id) in position 0
  EEPROM.write(0, 10);
}

void loop(){
  // The work is done, now just blink pin 0
  digitalWrite(0, HIGH);
  delay(500/16);
  digitalWrite(0, LOW);
  delay(500/16);

}
