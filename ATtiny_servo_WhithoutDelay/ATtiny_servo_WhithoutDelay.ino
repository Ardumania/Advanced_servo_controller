/*
 *  Pues, aunque parezca mentira, lo simple es lo que funciona,
 *  pero esto no funciona. A intervalos regulares de 1 segundo
 *  el servo pega un tiron
 *  
 */

const int servoPin =  0; 

unsigned long previousMicros = 0;

long intervalForHigh = 1500/8;
long intervalForLow = 18500/8;

boolean cicle = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);

  digitalWrite(servoPin, HIGH);
}

void loop() {

  unsigned long currentMicros = micros();

  if(cicle == true){
    if (currentMicros - previousMicros >= intervalForHigh) {
      cicle = false;
      digitalWrite(servoPin, LOW);
      previousMicros = currentMicros;
    }
  }
  if(cicle == false){
    if (currentMicros - previousMicros >= intervalForLow) {
      cicle = true;
      digitalWrite(servoPin, HIGH);
      previousMicros = currentMicros;
    }
  }
}
