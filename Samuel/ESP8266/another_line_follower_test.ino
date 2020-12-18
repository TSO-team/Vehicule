#include <Servo.h>
#include <SoftwareSerial.h>

String command, device;

SoftwareSerial BT1(10, 11); // El pin 10 es Rx y el pin 11 es Tx


int mode = 0;

#define STOPPED 0
#define FOLLOWING_LINE 1
#define NO_LINE 2

const int power = 500;
const int iniMotorPower = 250;
const int adj = 1;
float adjTurn = 8;

const int ledPin = 13;
const int buttonPin = 9;

// LFSensor more to the Left is "0"
const int lineFollowSensor0 = 12; 
const int lineFollowSensor1 = 18; 
const int lineFollowSensor2 = 17; 
const int lineFollowSensor3 = 16;
const int lineFollowSensor4 = 19;

int LFSensor[5]={0, 0, 0, 0, 0};

// PID controller
float Kp=50;
float Ki=0;
float Kd=0;

float error=0, P=0, I=0, D=0, PIDvalue=0;
float previousError=0, previousI=0;

#define RIGHT 1
#define LEFT -1

Servo leftServo;
Servo rightServo;




void motorStop() {
    leftServo.writeMicroseconds(1500);
    rightServo.writeMicroseconds(1500);
    delay(200);
}

void motorForward() {
    leftServo.writeMicroseconds(1500 - power);
    rightServo.writeMicroseconds(1500 + power*adj);
}

void motorBackward() {
    leftServo.writeMicroseconds(1500 + power);
    rightServo.writeMicroseconds(1500 - power);
}

void motorFwTime(unsigned int time) {
    motorForward();
    delay (time);
    motorStop();
}

void motorBwTime(unsigned int time) {
    motorBackward();
    delay (time);
    motorStop();
}

void motorTurn(int direction, int degrees) {
    leftServo.writeMicroseconds(1500 - iniMotorPower*direction);
    rightServo.writeMicroseconds(1500 - iniMotorPower*direction);
    delay (round(adjTurn*degrees+1));
    motorStop();
}

void motorPIDcontrol() {
    int leftMotorSpeed = 1500 - iniMotorPower - PIDvalue;
    int rightMotorSpeed = 1500 + iniMotorPower*adj - PIDvalue;
  
    // The motor speed should not exceed the max PWM value
    constrain(leftMotorSpeed, 1000, 2000);
    constrain(rightMotorSpeed, 1000, 2000);
  
    leftServo.writeMicroseconds(leftMotorSpeed);
    rightServo.writeMicroseconds(rightMotorSpeed);
}

void drivePolygon(unsigned int time, int sides) {
    for (int i = 0; i < sides; i++) {
        motorFwTime(time);
        motorTurn(RIGHT, 360 / sides);
    }
}







/* read line sensors values 
Sensor Array 	Error Value
0 0 0 0 1	 4              
0 0 0 1 1	 3              
0 0 0 1 0	 2              
0 0 1 1 0	 1              
0 0 1 0 0	 0              
0 1 1 0 0	-1              
0 1 0 0 0	-2              
1 1 0 0 0	-3              
1 0 0 0 0	-4              

1 1 1 1 1        0 Robot found continuous line : STOPPED
0 0 0 0 0        0 Robot found no line: turn 180o
*/

void readLFSsensors() {
    LFSensor[0] = digitalRead(lineFollowSensor0);
    LFSensor[1] = digitalRead(lineFollowSensor1);
    LFSensor[2] = digitalRead(lineFollowSensor2);
    LFSensor[3] = digitalRead(lineFollowSensor3);
    LFSensor[4] = digitalRead(lineFollowSensor4);

    if ((    LFSensor[0]== 0) && (LFSensor[1]== 0) && (LFSensor[2] == 0) && (LFSensor[3]== 0) && (LFSensor[4]== 1)) {mode = FOLLOWING_LINE; error = 4;}
    else if((LFSensor[0]== 0) && (LFSensor[1]== 0) && (LFSensor[2] == 0) && (LFSensor[3]== 1) && (LFSensor[4]== 1)) {mode = FOLLOWING_LINE; error = 3;}
    else if((LFSensor[0]== 0) && (LFSensor[1]== 0) && (LFSensor[2] == 0) && (LFSensor[3]== 1) && (LFSensor[4]== 0)) {mode = FOLLOWING_LINE; error = 2;}
    else if((LFSensor[0]== 0) && (LFSensor[1]== 0) && (LFSensor[2] == 1) && (LFSensor[3]== 1) && (LFSensor[4]== 0)) {mode = FOLLOWING_LINE; error = 1;}
    else if((LFSensor[0]== 0) && (LFSensor[1]== 0) && (LFSensor[2] == 1) && (LFSensor[3]== 0) && (LFSensor[4]== 0)) {mode = FOLLOWING_LINE; error = 0;}
    else if((LFSensor[0]== 0) && (LFSensor[1]== 1) && (LFSensor[2] == 1) && (LFSensor[3]== 0) && (LFSensor[4]== 0)) {mode = FOLLOWING_LINE; error =- 1;}
    else if((LFSensor[0]== 0) && (LFSensor[1]== 1) && (LFSensor[2] == 0) && (LFSensor[3]== 0) && (LFSensor[4]== 0)) {mode = FOLLOWING_LINE; error = -2;}
    else if((LFSensor[0]== 1) && (LFSensor[1]== 1) && (LFSensor[2] == 0) && (LFSensor[3]== 0) && (LFSensor[4]== 0)) {mode = FOLLOWING_LINE; error = -3;}
    else if((LFSensor[0]== 1) && (LFSensor[1]== 0) && (LFSensor[2] == 0) && (LFSensor[3]== 0) && (LFSensor[4]== 0)) {mode = FOLLOWING_LINE; error = -4;}
    else if((LFSensor[0]== 1) && (LFSensor[1]== 1) && (LFSensor[2] == 1) && (LFSensor[3]== 1) && (LFSensor[4]== 1)) {mode = STOPPED; error = 0;}
    else if((LFSensor[0]== 0) && (LFSensor[1]== 0) && (LFSensor[2] == 0) && (LFSensor[3]== 0) && (LFSensor[4]== 0)) {mode = NO_LINE; error = 0;}
}




void ledBlink(void) {
   for (int i = 0; i<4; i++) { 
      digitalWrite (ledPin, HIGH);
      delay (500);
      digitalWrite (ledPin, LOW);
      delay (500);
   } 
}

void checkBTcmd() {
   while (BT1.available()) {
     delay(10); //Delay added to make thing stable 
     char c = BT1.read(); //Conduct a serial read
     device += c; //build the string.
   }
   
   if (device.length() > 0) {
     Serial.print("Command received from BT ==> ");
     Serial.println(device); 
     command = device;
     device ="";  //Reset the variable
     BT1.flush();
   } 
}

void manualCmd() {
  switch (command[0]) {
    case 'f': 
      motorStop(); //turn off both motors
      break;

    case 'w':  
      motorForward();  
      break;

    case 'd':     
      motorTurn(RIGHT, 300);
      motorStop();
      
      break;

   case 'a': 
      motorTurn(LEFT, 300);
      motorStop();
      break;
    
    case 's':  
      motorBackward();
      break;
      
  }
}

void sendBTdata(int data) {
    digitalWrite (ledPin, HIGH);
    BT1.print("Data from Arduino");
    BT1.print(data);
    BT1.print(" xx");
    BT1.println('\n');
    digitalWrite (ledPin, LOW);
}

void calculatePID() {
    P = error;
    I = I + error;
    D = error-previousError;
    PIDvalue = (Kp*P) + (Ki*I) + (Kd*D);
    previousError = error;
}

void testLineFollowSensors() {
    int LFS0 = digitalRead(lineFollowSensor0);
    int LFS1 = digitalRead(lineFollowSensor1);
    int LFS2 = digitalRead(lineFollowSensor2);
    int LFS3 = digitalRead(lineFollowSensor3);
    int LFS4 = digitalRead(lineFollowSensor4);

    Serial.print ("LFS: L  0 1 2 3 4  R ==> "); 
    Serial.print (LFS0); 
    Serial.print (" ");
    Serial.print (LFS1); 
    Serial.print (" ");
    Serial.print (LFS2); 
    Serial.print (" ");
    Serial.print (LFS3); 
    Serial.print (" ");
    Serial.print (LFS4); 
    Serial.print ("  ==> ");

    Serial.print (" P: ");
    Serial.print (P);
    Serial.print (" I: ");
    Serial.print (I);
    Serial.print (" D: ");
    Serial.print (D);
    Serial.print (" PID: ");
    Serial.println (PIDvalue);
}







void setup() {
  Serial.begin(9600);
  BT1.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(lineFollowSensor0, INPUT);
  pinMode(lineFollowSensor1, INPUT);
  pinMode(lineFollowSensor2, INPUT);
  pinMode(lineFollowSensor3, INPUT);
  pinMode(lineFollowSensor4, INPUT);
  
  leftServo.attach(5);
  rightServo.attach(3);
  
  BT1.print("MJRobot Line Follower is alive");
  BT1.println('\n');
  Serial.println("MJRobot Line Follower is alive ==> Presss the button to start");

  while (digitalRead(buttonPin)) {}
}

void loop() {
    readLFSsensors();    
    switch (mode) {
    case STOPPED: 
      motorStop();
      BT1.print("The End");
      ledBlink();
      previousError = error;
      break;

    case NO_LINE:  
      motorStop();
      motorTurn(LEFT, 180);
      previousError = 0;
      break;

    case FOLLOWING_LINE:     
      calculatePID();
      motorPIDcontrol();    
      break;     
  }
}
