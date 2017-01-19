# Advanced_servo_controller
Based on ATtiny85 and PJON bus

In the last years I have worked in several projects related with education and robotics 
and I have found several problems, if you work with only one microcontroller you are very 
limited about the number of servos you can drive, you need a separate controller to 
drive until 32 servos, but it’s still possible. What about sensors? if you are planning 
to build an hexapod and mount two distance sensor for each leg It’s practically impossible.

There are systems for robotics that consist in smart servos connected by a RS-485 bus 
(Dynamixel or Ubtech), but in these systems is not possible to implement sensors on the 
same bus. And other problem is that those systems use a closed protocol and developers 
can’t implement their own sensors or actuators.

For several time I was thinking in an alternative system for implement sensors and actuators 
in a same communication bus and, of course, do it open allowing developers and enthusiast to 
design their own modules and share them. Initially thought in I2C bus be cause is well 
documented and easy to use but need 4 wires and there are no standard cable to use, this 
is an inconvenient.

In May 2015 I was talking in Valencia with my mentor and friend David Cuartielles about 
this project and he made me a suggestion: the PJON bus developed by an italian guy 
(Giovanni Blu), it’s one wire, addressable, fully bi-directional and open. That was 
instant love and this project could start.
PJON project can be found here: https://github.com/gioblu/PJON

The main goal of this project is to build a net of modules that can talk to each others
and with the main controller by only a one wire. Just think about it: one wire for data, 
one wire for GND and another wire for VCC, you can have a net of actuators and sensors 
just connected by standard servo wires… and can be connected up to 256 devices.

The first prototype is a servo module, actually called Advanced Servo Controller, and 
is in a very early state of development but it will work for sure be cause the concept 
is very simple: a small pcb with an ATtiny85 that communicates with a main controller 
(Arduino, of course) via a PJON bus, this ATtiny receives commands and generates the 
servo control signals. Commands can be like AT commands, e.g. “GT1500,2000”, this is 
Go To position 1500 in 2000 milliseconds, position is the servo control signal duty 
cycle in microseconds and final time is the time in which must reach that position 
from its actual position… simple. Each module has a current sensor a can send readings 
to the main controller as responses to a specific requests… and more capabilities can 
be implemented in the module firmware in the future.

In the future can be implemented more types of modules with sensors, e.g. distance sensors, 
which are very interesting in robotics. 
