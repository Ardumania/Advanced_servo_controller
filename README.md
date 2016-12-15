# Advanced_servo_controller
Based on ATtiny85 and PJON bus

La carpeta ATtiny_PJON_ICSP contiene los archivos Eagle de la placa en su primera versión, esta será sólo de pruebas,
ya se ha visto que hay otros componentes que son más interesantes de instalar en la placa que el led RGB. Esto se hará 
en próximas versiones.

La carpeta ATtiny_servo_sweep es un intento de generar una señal de control de servo desde el ATtiny85, se utiliza la función
delayMicroseconds y el resultado no es estable.

En el programa para Arduino ATtiny_servo_WithoutDelay se a utilizado el ejemplo BlinkWithoutDelay modificado para generar
la señal de control del servo sin recurrir a la función delay.... pero el resultado es el mismo que que utilizando delay.
Empiezo a pensar que no es cosa de software si no de hardware, actualmente alimento el servo desde el programador ArduinoISP
y, aunque es un servo de 9g, es posible que no reciba suficiente corriente y por ello su comportamiento sea "tembloroso"
