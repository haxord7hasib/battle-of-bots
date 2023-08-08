#include <Servo.h>

Servo esc; 
int L_EN_FOR_ONE = 3;
int R_EN_FOR_ONE = 4;
int L_PWM_FOR_ONE = 5;
int R_PWM_FOR_ONE = 6;
int L_EN_FOR_TWO = 8;
int R_EN_FOR_TWO = 12;
int L_PWM_FOR_TWO = 10;
int R_PWM_FOR_TWO = 11;
char incomingByte; // for incoming serial data
int speed_min = 155; // the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255;

int speed_left = speed_max; // set both motors to maximum speed
int speed_right = speed_max;

void left();
void right();
void forward();
void backward();
void forward_left();
void forward_right();
void back_left();
void back_right();

void setup() {
  esc.attach(9);  // Attach the ESC signal pin to digital pin 9
  Serial.begin(9600);  // Initialize the serial communication

  pinMode(L_EN_FOR_ONE, OUTPUT);
  pinMode(R_EN_FOR_ONE, OUTPUT);
  pinMode(L_PWM_FOR_ONE, OUTPUT);
  pinMode(R_PWM_FOR_ONE, OUTPUT);
  pinMode(L_EN_FOR_TWO, OUTPUT);
  pinMode(R_EN_FOR_TWO, OUTPUT);
  pinMode(L_PWM_FOR_TWO, OUTPUT);
  pinMode(R_PWM_FOR_TWO, OUTPUT);

  digitalWrite(L_EN_FOR_ONE, HIGH);
  digitalWrite(R_EN_FOR_ONE, HIGH);
  digitalWrite(L_EN_FOR_TWO, HIGH);
  digitalWrite(R_EN_FOR_TWO, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }
  
  switch (incomingByte) {
    case 'S':
      stopo();
      incomingByte = '*';
      break;
    case 'R':
      left();
      incomingByte = '*';
      break;
    case 'F':
      forward();
      incomingByte = '*';
      break;
    case 'L':
      right();
      incomingByte = '*';
      break;
    case 'B':
      backward();
      incomingByte = '*';
      break;
    case '1':
      speed_left = 20;
      speed_right = 20;
      incomingByte = '*';
      break;
    case '2':
      speed_left = 40;
      speed_right = 40;
      incomingByte = '*';
      break;
    case '3':
      speed_left = 60;
      speed_right = 60;
      incomingByte = '*';
      break;
    case '4':
      speed_left = 80;
      speed_right = 80;
      incomingByte = '*';
      break;
    case '5':
      speed_left = 100;
      speed_right = 100;
      incomingByte = '*';
      break;
    case '6':
      speed_left = 120;
      speed_right = 120;
      incomingByte = '*';
      break;
    case '7':
      speed_left = 140;
      speed_right = 140;
      incomingByte = '*';
      break;
    case '8':
      speed_left = 160;
      speed_right = 160;
      incomingByte = '*';
      break;
    case '9':
      speed_left = 200;
      speed_right = 200;
      incomingByte = '*';
      break;
    case 'q':
      speed_left = 255;
      speed_right = 255;
      Serial.println("Speed full \n");
      incomingByte = '*';
      break;
    case 'I':
      back_right();
      Serial.println("Speed full \n");
      incomingByte = '*';
      break;
    case 'H':
      forward_left();
      Serial.println("Speed full \n");
      incomingByte = '*';
      break;
    case 'J':
      forward_right();
      Serial.println("Speed full \n");
      incomingByte = '*';
      break;
    case 'G':
      back_left();
      Serial.println("Speed full \n");
      incomingByte = '*';
      break;
    case 'W':
      // Set ESC to full speed
      esc.writeMicroseconds(1400);
      delay(100);
      esc.writeMicroseconds(1500);
      delay(100);
      esc.writeMicroseconds(1600);
      
      break;
    case 'U':
      // Set ESC to half speed
      esc.writeMicroseconds(1300);
      break;
    case 'u':
      // Stop the ESC
      esc.writeMicroseconds(1000);
      break;
  }
}

void forward() {
  analogWrite(R_PWM_FOR_ONE, speed_left);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, speed_right);
}

void backward() {
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, speed_left);
  analogWrite(R_PWM_FOR_TWO, speed_right);
  analogWrite(L_PWM_FOR_TWO, 0);
}

void right() {
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, speed_left);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, speed_right);
}

void left() {
  analogWrite(R_PWM_FOR_ONE, speed_left);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, speed_right);
  analogWrite(L_PWM_FOR_TWO, 0);
}

void stopo() {
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, 0);
}

void forward_left() {
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, speed_right);
  analogWrite(L_PWM_FOR_TWO, 0);
}

void forward_right() {
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, speed_left);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, 0);
}

void back_left() {
  analogWrite(R_PWM_FOR_ONE, 0);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, speed_right);
}

void back_right() {
  analogWrite(R_PWM_FOR_ONE, speed_left);
  analogWrite(L_PWM_FOR_ONE, 0);
  analogWrite(R_PWM_FOR_TWO, 0);
  analogWrite(L_PWM_FOR_TWO, 0);
}
