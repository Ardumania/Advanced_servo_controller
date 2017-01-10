# Advanced_servo_controller
Based on ATtiny85 and PJON bus

Eagle folder contains the board Eagle files, now in a new configuration. The RGB LED has been removed and added an external
oscillator for the ATtiny85, pads to solder a NTC resistor as a temperature sensor and a hole to place this sensor close 
to the servo.
This dessingn is waiting for @JavierIH approval ;)

La carpeta ATtiny_servo_sweep es un intento de generar una señal de control de servo desde el ATtiny85, se utiliza la función
delayMicroseconds y el resultado no es estable.

En el programa para Arduino ATtiny_servo_WithoutDelay se a utilizado el ejemplo BlinkWithoutDelay modificado para generar
la señal de control del servo sin recurrir a la función delay.... pero el resultado es el mismo que que utilizando delay.
Empiezo a pensar que no es cosa de software si no de hardware, actualmente alimento el servo desde el programador ArduinoISP
y, aunque es un servo de 9g, es posible que no reciba suficiente corriente y por ello su comportamiento sea "tembloroso"
