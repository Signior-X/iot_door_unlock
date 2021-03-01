char t;

#include <Servo.h>
Servo servo;
int angle = 10;

void setup() {

  servo.attach(9);
  servo.write(angle);

  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'w') {          //move forward(all motors rotate in forward direction)
    Serial.println("hello");

    for (angle = 10; angle < 180; angle++)
    {
      servo.write(angle);
      delay(15);
    }
  }

  else if (t == 'a') {    //move reverse (all motors rotate in reverse direction)
    Serial.println("Bye");

    for (angle = 180; angle > 10; angle--)
    {
      servo.write(angle);
      delay(15);
    }
  }


  delay(100);
}
