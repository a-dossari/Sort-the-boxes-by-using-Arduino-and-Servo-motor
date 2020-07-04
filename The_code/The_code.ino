#include <Servo.h> //Arduino servo motor library

//configure the servo motor
Servo servo;

//the connection of the LEDs and LDR sensors in the pins of arduino board
int LED1 = 6;
int LED2 = 5;
int LED3 = 4;

int LDR1 = A1;
int LDR2 = A2;
int LDR3 = A3;


void setup() {
  //the connection of the servo motor in the pins of arduino board
  servo.attach(8);
  
  //configure the pins as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  //configure the pins as input pull-up
  pinMode(LDR1, INPUT_PULLUP);
  pinMode(LDR2, INPUT_PULLUP);
  pinMode(LDR3, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int Value_LDR1 = digitalRead(LDR1); // Value_LDR1 reads and saves the digital value of LDR1
  int Value_LDR2 = digitalRead(LDR2); // Value_LDR2 reads and saves the digital value of LDR2
  int Value_LDR3 = digitalRead(LDR3); // Value_LDR3 reads and saves the digital value of LDR3

  int btn_Large = digitalRead(13); // btn_Large reads and saves the digital value of pin 13
  int btn_Medium = digitalRead(12); // btn_Medium reads and saves the digital value of pin 12
  int btn_Small = digitalRead(11); // btn_Small reads and saves the digital value of pin 11


  if (Value_LDR1 == LOW && Value_LDR2 == LOW && Value_LDR3 == LOW) // It means the box is large since the height of the box blocked all the LDR sensors
  {
    servo.write(90);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);  
  }
  else if (Value_LDR1 == HIGH && Value_LDR2 == LOW && Value_LDR3 == LOW) // It means the box is medium since the height of the box blocked the bottom and the middle sensors
  {
    servo.write(120);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);  
    }
  else if (Value_LDR1 == HIGH && Value_LDR2 == HIGH && Value_LDR3 == LOW)  // It means the box is small since the height of the box blocked the bottom sensor only
  {
    servo.write(60);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    }

  else if (Value_LDR1 == HIGH && Value_LDR2 == HIGH && Value_LDR3 == HIGH) // It means there is no box since the sensors aren't blocked
  {
    servo.write(180); 
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  // In case the sensors are damaged, we can use the buttons

  if(btn_Large == HIGH) //if btn_Large is pressed
  {
    servo.write(90);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH); 
  }

    if(btn_Medium == HIGH) //if btn_Medium is pressed
  {
    servo.write(120);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH); 
  }

    if(btn_Small == HIGH) //if btn_Small is pressed
  {
    servo.write(60);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
  }
}
