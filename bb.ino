#include <Servo.h>

Servo esc; 
int L_EN_FOR_ONE=3;
int R_EN_FOR_ONE=4;
int L_PWM_FOR_ONE=5;
int R_PWM_FOR_ONE=6;
int L_EN_FOR_TWO=8;
int R_EN_FOR_TWO=12;
int L_PWM_FOR_TWO=10;
int R_PWM_FOR_TWO=11;
char incomingByte; // for incoming serial data
int speed_min = 155; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255; //

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
   esc.attach(9);
  Serial.begin(9600);
pinMode(L_EN_FOR_ONE,OUTPUT);
pinMode(R_EN_FOR_ONE,OUTPUT);
pinMode(L_PWM_FOR_ONE,OUTPUT);
pinMode(R_PWM_FOR_ONE,OUTPUT);
pinMode(L_EN_FOR_TWO,OUTPUT);
pinMode(R_EN_FOR_TWO,OUTPUT);
pinMode(L_PWM_FOR_TWO,OUTPUT);
pinMode(R_PWM_FOR_TWO,OUTPUT);

digitalWrite(L_EN_FOR_ONE,HIGH);
digitalWrite(R_EN_FOR_ONE,HIGH);
digitalWrite(L_EN_FOR_TWO,HIGH);
digitalWrite(R_EN_FOR_TWO,HIGH);
}

void loop() {

if (Serial.available() > 0) {
    incomingByte = Serial.read();
    }
  switch(incomingByte)
  {
     case 'W':
      {
        esc.writeMicroseconds(1000);
        stopo();
       //Serial.println("Stop\n"); 
       incomingByte='*';}
     break;
    

     
     case 'R':
      
     {  left();
       
      // Serial.println("Forward\n");
       incomingByte='*';}
     break;
    
      case 'F':
       esc.writeMicroseconds(1500);
    {   forward();
      // Serial.println("Backward\n");
       incomingByte='*';}
     break;
     break;
     
     case 'L':
     // turn right
     {  
       right(); 
      // Serial.println("Rotate Right\n");
       incomingByte='*';}
     break;
       case 'B':
      { 
       backward();     
       //Serial.println("Rotate Left\n");
       incomingByte='*';}
     break;
     case '1':
        
      { speed_left = 20; 
       speed_right = 20;
       //Serial.println("Speed 1\n");
       incomingByte='*';}
     break;
    case '2':
      { 
        speed_left = 40; 
       speed_right = 40;
       //Serial.println("Speed 2 \n");
       incomingByte='*';}
     break;
    case '3':
      { 
        speed_left = 60; 
       speed_right = 60;
       //Serial.println("Speed 3 \n");
       incomingByte='*';}
     break; 
        case '4':
      { 
        speed_left = 80; 
       speed_right = 80;
       //Serial.println("Speed 4 \n");
       incomingByte='*';}
     break; 
        case '5':
      { 
        speed_left = 100; 
       speed_right = 100;
       //Serial.println("Speed 5 \n");
       incomingByte='*';}
     break; 
        case '6':
      { 
        speed_left = 120; 
       speed_right = 120;
       //Serial.println("Speed 6 \n");
       incomingByte='*';}
     break; 
        case '7':
      { 
        speed_left = 140; 
       speed_right = 140;
      // Serial.println("Speed 7 \n");
       incomingByte='*';}
     break; 
        case '8':
      { 
        speed_left = 160; 
       speed_right = 160;
       //Serial.println("Speed 8 \n");
       incomingByte='*';}
     break; 
        case '9':
      { 
        speed_left = 200; 
       speed_right = 200;
       //Serial.println("Speed 9 \n");
       incomingByte='*';}
     break; 
        case 'q':
      { 
        speed_left = 255; 
       speed_right = 255;
       Serial.println("Speed full \n");
       incomingByte='*';}
     break; 
        case 'I':
      { 
       back_right();//forward_right
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'H':
      { 
       forward_left();//back_left
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'J':
      { 
       //back_right();
       forward_right(); //back_right
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'G':
      { 
       back_left();//forward_left
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;  
          case 'U':
      { 
        esc.writeMicroseconds(1200);
        delay(5000);
        esc.writeMicroseconds(1400);
        delay(5000);
      
       incomingByte='*';}
     break;  
      case 'V':
      { 
        esc.writeMicroseconds(1600);
        delay(5000);
        esc.writeMicroseconds(1800);
        delay(5000);
      
       incomingByte='*';}
     break;  
      case 'X':
      { 
        speed_left = 255; 
       speed_right = -255;
      
       incomingByte='*';}
     break;  
     
  }

  
}
void forward(){

  analogWrite(R_PWM_FOR_ONE,speed_left);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,speed_right);
  };
void backward(){
    analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,speed_left);
  analogWrite(R_PWM_FOR_TWO,speed_right);
  analogWrite(L_PWM_FOR_TWO,0);
  };
void right(){
   analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,speed_left);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,speed_right);
  };
void left(){
     analogWrite(R_PWM_FOR_ONE,speed_left);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,speed_right);
  analogWrite(L_PWM_FOR_TWO,0);
  
  
  };
void stopo(){

    analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,0);
  
  
  };
void forward_left(){
   analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,speed_right);
  analogWrite(L_PWM_FOR_TWO,0);
  
  
  };
void forward_right(){
     analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,speed_left);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,0);
  };
void back_left(){
      analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,speed_right);
  
  };
void back_right(){
      analogWrite(R_PWM_FOR_ONE,speed_left);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,0);
  
  
  };
