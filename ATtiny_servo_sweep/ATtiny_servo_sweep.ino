/*
 *  Simple sweep generating control signal by hand
 *  
 *  ATtiny85 running at 8MHz, code uploaded with ArduinoISP
 *  
 *  You will find the argument of delayMicroseconds divided by 8, 
 *  this is because the ATtiny is running at 8MHz and at this speed
 *  delay and delayMicroseconds are 8 times slower... don't ask me why.
 *  The same effect happens when running at 16MHz, but 16 times slower.
 *  
 *  This code seems work well but something stange happens: there is a 
 *  twiching effect in intervals of 1 sec apoximately... and should not do it.
 *  
 */

const int servoPin =  0; 

int cont = 0; // to count cicles
int cicles = 1; // number of cicles between movements, this determine the speed
int dutyCicle = 1000; // in microSeconds, initial position of the servo
int upperLimit = 2000;
int lowerLimit = 1000;
boolean rising = true; // to do a sweep, dutyCicle is rising? rising = true
                       // then, when dutyCicle is falling rising = false

void setup() {
  
  pinMode(servoPin, OUTPUT);

  // 1 sec in dutyCicle = 1000
  for(int i = 0; i <= 50;){
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(dutyCicle/8);
    digitalWrite(servoPin, LOW);
    delayMicroseconds((20000 - dutyCicle)/8);
    i++;
  }
}

void loop() {

  // A complete cicle
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(dutyCicle/8);
  digitalWrite(servoPin, LOW);
  delayMicroseconds((20000 - dutyCicle)/8);
  // increment the counter
  cont++;

  // when necessary reset the counter and increment or decrement dutyCicle
  if(cont >= cicles){
    cont = 0;
    if(rising){
      dutyCicle += 5;
    }else{
      dutyCicle -= 5;
    }
    // if dutyCicle is out of limits invert rising
    if(dutyCicle > upperLimit) rising = false;
    if(dutyCicle < lowerLimit) rising = true;
  }
}

