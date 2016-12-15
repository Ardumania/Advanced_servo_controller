# Advanced_servo_controller
Based on ATtiny85 and PJON bus

La carpeta ATtiny_PJON_ICSP contiene los archivos Eagle de la placa en su primera versión, esta será sólo de pruebas,
ya se ha visto que hay otros componentes que son más interesantes de instalar en la placa que el led RGB. Esto se hará 
en próximas versiones.

La carpeta ATtiny_servo_sweep es un intento de generar una señal de control de servo desde el ATtiny85, se utiliza la función
delayMicroseconds y el resultado no es estable.

TODO: crear otro algoritmo para crear la señal de control del servo sin utilizar la función delayMicroseconds, la mejor
opción que se me ocurre es modificar el código de ejemplo BlinkWithoutDelay y generar la señal de control con el.
