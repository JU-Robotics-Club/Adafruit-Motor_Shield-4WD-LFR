//ARDUINO LINE FOLLOWING CAR//
// YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
// GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //
 
//including the libraries
#include <AFMotor.h>


//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //begin serial communication
  Serial.begin(9600);
  
}

int s1, s2, s3, s4, s5;
void sensorRead() {
//   s1 = digitalRead(ir1);  //Left Most Sensor
//   s2 = digitalRead(ir2);  //Left Sensor
//   s3 = digitalRead(ir3);  //Middle Sensor
//   s4 = digitalRead(ir4);  //Right Sensor
//   s5 = digitalRead(ir5);  //Right Most Sensor
// }
}

void goRight()
{
    motor1.run(BACKWARD);
    motor1.setSpeed(250);
    motor2.run(BACKWARD);
    motor2.setSpeed(250);
    motor3.run(FORWARD);
    motor3.setSpeed(250);
    motor4.run(FORWARD);
    motor4.setSpeed(250);
}
void goLeft()
{
    motor1.run(FORWARD);
    motor1.setSpeed(250);
    motor2.run(FORWARD);
    motor2.setSpeed(250);
    motor3.run(BACKWARD);
    motor3.setSpeed(250);
    motor4.run(BACKWARD);
    motor4.setSpeed(250);
}

void goForward()
{
    motor1.run(FORWARD);
    motor1.setSpeed(250);
    motor2.run(FORWARD);
    motor2.setSpeed(250);
    motor3.run(FORWARD);
    motor3.setSpeed(250);
    motor4.run(FORWARD);
    motor4.setSpeed(250);
  
}

void goStop(){
   motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
}

void loop() {
  // sensorRead();
  //setSpeed(80);
  //if only middle sensor detects black line
 //goLeft();
goForward(); 
  
}
