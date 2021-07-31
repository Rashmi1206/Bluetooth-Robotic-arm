#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo V1;  //up and down
Servo V2;  //right and left
Servo V3;  //pick drop
int angle=0;
char movement;  //for servo as well as motors

void setup()
{ 
  V1.attach(9);
  V2.attach(10);
  V3.attach(4);
  Serial.begin(9600);
}

void loop(){
  
  if(Serial.available() >0) {
    movement = Serial.read();
    Stop();
    switch(movement){
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
       case 'U':
      upwards();
      break;
    case 'D':
      downwards();
      break;
    case 'X':
       s_right();
       break;
    case 'Y':
       s_left();
       break; 
    case 'Z' :
       s_drop();
       break;        
    }
  }
}


void upwards(){
for (angle=0; angle<100;angle++)
{V1.write(angle);
 delay(10);  
}
}

void downwards(){
for(angle=100;angle>=1;angle--){
  V1.write(angle);
  delay(10);}
  delay(200);
for (angle=90; angle>=1;angle--){
  V3.write(angle);
  delay(10);}
  delay(300);
}

void s_right(){
 for (angle=0; angle<100;angle++){
  V2.write(angle);
  delay(10);}
}

void s_left(){
  for(angle=100;angle>=1;angle--){
    V2.write(angle);
    delay(10);}
}

void s_drop(){
  for(angle=0;angle<=70;angle++){
    V3.write(angle);
    delay(10);}
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(0); //Define maximum velocity
  motor1.run(RELEASE); //rotate the motor anti-clockwise
  motor2.setSpeed(0); //Define maximum velocity
  motor2.run(RELEASE); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(0); //Define maximum velocity
  motor3.run(RELEASE); //rotate the motor anti-clockwise
  motor4.setSpeed(0); //Define maximum velocity
  motor4.run(RELEASE); //rotate the motor anti-clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
