/*
 * Advanced Servo Controller Firmware
 * by Jose Manuel Escuder
 * ver 0.1 January 20th, 2017
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
PhysicalPin  ATtiny Pin       Function
    1         reset             can't use
    2         digital 3, A3     Xtal
    3         digital 4, A2     Xtal
    5         digital 0 (PWM)   servo signal
    6         digital 1 (PWM)   PJON Bus
    7         digital 2, A1     ADC1
 */

// do a more efficient use of memory changing the defect values by
// these new, the maximum number of packets this module can handle
// is 2 and these packets has a limited length of 5 bytes
#define MAX_PACKETS 2
#define PACKET_MAX_LENGTH 5

#include <PJON.h>

#include <EEPROM.h>

PJON<SoftwareBitBang> bus;

int positionToGo, actualPosition;
int timeToGo;

void setup() {
  // the device id is stored in the EEPROM,
  // in the position 0, going to read it and
  // set it as bus id. If the module is new the 
  // id by default is 10
  int id;
  EEPROM.get(0, id);
  bus.set_id(id);

  // The pin bus is 3
  bus.strategy.set_pin(3);
  // Set what to do when a request is received
  bus.set_receiver(receiver_function);
  // Start communication
  bus.begin();
}

void receiver_function(uint8_t *payload, uint16_t length, const PacketInfo &packet_info) {
  // command GoTo, reach a new position in a determined time
  if(char(payload[0]) == 'G'){ 

    positionToGo = byte(payload[1]);
    positionToGo = positionToGo << 8;
    positionToGo |= byte(payload[2]);
    
    timeToGo = byte(payload[3]);
    timeToGo = timeToGo << 8;
    timeToGo |= byte(payload[4]);
  }

  // command Read, read the ACS712 and send a response to the master
  if(char(payload[0]) == 'R'){
    int lecture = analogRead(A1);
    char content[2] = {lecture >> 8, lecture & 0xFF};
    bus.reply(content, 2);
    bus.update();
  }

  // command NewId, change the module Id 
  if(char(payload[0]) == 'N'){
    int newId = byte(payload[1]);
    EEPROM.put(0, newId);
    bus.set_id(newId); 
  }
}

void loop() {
  bus.receive();

  /*
   * now move the servo... work in progress
   * 
   */
};
