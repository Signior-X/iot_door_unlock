char t;

#include <Servo.h>
Servo servo;
int angle = 10; //initial angle is 10 degree

void setup() {

  servo.attach(9);
  servo.write(angle);
  //set initial angle to 10 degree each time regardless of last position

  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
  //check if app is connected through bluetooth and ready to give output
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'w') {          
  //move forward(all motors rotate in forward direction)
   // Serial.println("hello");  for debugging

    for (angle = 10; angle < 180; angle++)
    {
      servo.write(angle);
      delay(15);
    }
  }

  else if (t == 'a') {    
    //move reverse (all motors rotate in reverse direction)
   // Serial.println("Bye");  for debugging

    for (angle = 180; angle > 10; angle--)
    {
      servo.write(angle);
      delay(15);
    }
  }


  delay(100);
}
