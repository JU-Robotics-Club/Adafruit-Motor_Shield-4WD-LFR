//ARDUINO LINE FOLLOWING CAR//
// YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
// GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //

//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //declaring pin types
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  //begin serial communication
  Serial.begin(9600);
}

int s1, s2, s3, s4, s5;
void sensorRead() {
  s1 = digitalRead(ir1);  //Left Most Sensor
  s2 = digitalRead(ir2);  //Left Sensor
  s3 = digitalRead(ir3);  //Middle Sensor
  s4 = digitalRead(ir4);  //Right Sensor
  s5 = digitalRead(ir5);  //Right Most Sensor
}

void goRight() {
  if (s5 == 0) {
    motor1.run(BACKWARD);
    motor1.setSpeed(250);
    motor2.run(BACKWARD);
    motor2.setSpeed(250);
    motor3.run(FORWARD);
    motor3.setSpeed(250);
    motor4.run(FORWARD);
    motor4.setSpeed(250);
  } else if (s4 == 0) {
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(FORWARD);
    motor3.setSpeed(250);
    motor4.run(FORWARD);
    motor4.setSpeed(250);
  }
}
void goLeft() {
  if (s1 == 0) {
    motor1.run(FORWARD);
    motor1.setSpeed(250);
    motor2.run(FORWARD);
    motor2.setSpeed(250);
    motor3.run(BACKWARD);
    motor3.setSpeed(250);
    motor4.run(BACKWARD);
    motor4.setSpeed(250);
  } else if (s2 == 0) {
    motor1.run(FORWARD);
    motor1.setSpeed(250);
    motor2.run(FORWARD);
    motor2.setSpeed(250);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
  }
}

void goForward() {
  motor1.run(FORWARD);
  motor1.setSpeed(100);
  motor2.run(FORWARD);
  motor2.setSpeed(100);
  motor3.run(FORWARD);
  motor3.setSpeed(100);
  motor4.run(FORWARD);
  motor4.setSpeed(100);
}
void goF(int s) {
  motor1.run(FORWARD);
  motor1.setSpeed(s);
  motor2.run(FORWARD);
  motor2.setSpeed(s);
  motor3.run(FORWARD);
  motor3.setSpeed(s);
  motor4.run(FORWARD);
  motor4.setSpeed(s);
}

void goStop() {
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
  sensorRead();
  //setSpeed(80);
  //if only middle sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    goForward();
    // delay(200);
  }
  if ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 0)) {
    goForward();
    // delay(200);
  }
  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    goForward();
    // delay(200);
  }

  //if only left sensor detects black line
  if ((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)) {
    goLeft();
    delay(50);
  }

  //if only left most sensor detects black line
  if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1)) {
    goLeft();
    delay(200);
  }

  //if only right sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1)) {
    goRight();
    delay(100);
  }

  //if only right most sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0)) {
    goRight();
    delay(200);
  }

  //if middle and right sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1)) {
    goRight();
    // delay(200);
  }

  //if middle and left sensor detects black line
  if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    goLeft();
    // delay(200);
  }

  //if middle, left and left most sensor detects black line
  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    goLeft();
    // delay(200);
  }

  //if middle, right and right most sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    goRight();
    // delay(200);
  }

  //  if left and middle find black line
  if ((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    goLeft();
    //delay(200);
  }

  //  if Right and middle find black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 0)) {
    goRight();
    delay(200);
  }



  //if all sensors are on a black line
  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    //stop
    goF(80);
    sensorRead();
    goStop();
  }

  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1)) {
    goLeft();
    // delay(200);
  }
  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0)) {
    goLeft();
    delay(50);
  }
  if ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0)) {
    goLeft();
    delay(50);
  }
  if ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)) {
    goLeft();
    // delay(200);
  }
  if ((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    goRight();
    delay(50);
  }
  if ((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1)) {
    goLeft();
    delay(200);
  }
  if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0)) {
    goRight();
    delay(200);
  }
  if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1)) {
    goLeft();
    delay(200);
  }

  if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    goRight();
    // delay(200);
  }
  if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1)) {
    goForward();
    // delay(200);
  }
  if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0)) {
    goRight();
    delay(200);
  }
  if ((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0)) {
    goRight();
    delay(100);
  }
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 0)) {
    goRight();
    delay(100);
  }
  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0)) {
    goRight();
    // delay(200);
  }
}
