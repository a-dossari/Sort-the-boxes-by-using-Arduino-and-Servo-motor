# Sorting the boxes by using Arduino.

I design a control system for a production line, to sort three sizes of boxes, which are: large (30x30x30), medium (20x20x20), and small (10x10x10).

As you can see in the file, the sensors are placed vertically, and the distance between each other is 10 cm. When the box passes in front of the sensors, the system will know the size of the box by knowing the number of sensors that detected the box (for example: the size of the box is medium if the number of sensors is 2). The LEDs also show the size of the box, each LED lights up when the sensor detects the box (for example: when the bottom sensor only detects the box, the bottom LED will light up, then you will know that the box is small). After the system knows the size of the box, the motor will rotate to a specific angle to make the box move to a specific direction, and each size has a certain angle. I used the buttons for safety, in case if the sensors are damaged or an error occurs. 

There are videos similar to what I did, which are:

**Determine the size of the box by using the sensors**:


<a href="http://www.youtube.com/watch?feature=player_embedded&v=8lFLSxjw6Uc
" target="_blank"><img src="http://img.youtube.com/vi/8lFLSxjw6Uc/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="480" height="360" border="10" /></a>



**Sorting boxess according to the size of the box**:


<a href="http://www.youtube.com/watch?feature=player_embedded&v=Fbx3inwxOPo
" target="_blank"><img src="http://img.youtube.com/vi/Fbx3inwxOPo/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="480" height="360" border="10" /></a>



To build the circuit, I used:

- Arduino board.

- Servo motor.

- Three LDR sensors.

- Three LEDs for the sensors.

- Three buttons, for safety.
