#include <Servo.h>

Servo myServo;

//yellow wire
int const potPin=A0;
//potentiometer value
int potVal;
//angle for the servo to move to
int angle;

void setup() {
  myServo.attach(9);
 Serial.begin(9600);
 Serial.print(
}

void loop() {

  potVal=analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  
  //change the values between 0-1023 to values between 0-179
  //five arguments, number to be scaled (potVal), mim number 
  //of input 0, max value of input (1023), 
  //mim value of output (0),
  //and lastly max value of output (179)
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
