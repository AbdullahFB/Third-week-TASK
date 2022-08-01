#include <Servo.h>
Servo gripper;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;

double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;


void setup() {
 Serial.begin(115200);
   base.attach(8);
  shoulder.attach(9); 
  elbow.attach(10);
  wrist.attach(11);
  gripper.attach(12); 

  base.write(base_angle);
  shoulder.write(shoulder_angle);
  elbow.write(elbow_angle);
  wrist.write(wrist_angle);

}

void loop() {
  
  String  data= Serial.readString();
  if (data.indexOf("right")) {
    base.write(base_angle -= 20);
  }
 
  else if (data.indexOf("left")) {
    base.write(base_angle += 20);
  }
   
    Serial.println(data);
  delay(10000);

}
