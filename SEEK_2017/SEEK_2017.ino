#include <Servo.h>
Servo laserServo;
char val; // variable to receive data from the serial port
int ledPin = 13; // LED connected to pin 13 (on-board LED)
int leftMotorPinHigh = 5;
int leftMotorPinLow = 6;
int rightMotorPinHigh = 7;
int rightMotorPinLow = 8;
int servoPin = 9;
int laserPin = 4;
int servoPosition = 130;
int delayTime = 100;

void setup() {
  
  pinMode(ledPin, OUTPUT);  // pin 13 (on-board LED)  OUTPUT
  pinMode(leftMotorPinHigh, OUTPUT);
  pinMode(leftMotorPinLow, OUTPUT);
  pinMode(rightMotorPinHigh, OUTPUT);
  pinMode(rightMotorPinLow, OUTPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(laserPin, OUTPUT);

  laserServo.attach(servoPin);
  laserServo.write(servoPosition);
  Serial.begin(9600);       // start serial communication at 9600bps

}

void loop() {

  if( Serial.available() )       // if data is available to read
  {
    val = Serial.read();         // read it and store it in 'val'
  } else {
    val = NULL;
    digitalWrite(leftMotorPinHigh, LOW);
    digitalWrite(leftMotorPinLow, LOW);
    digitalWrite(rightMotorPinHigh, LOW);
    digitalWrite(rightMotorPinLow, LOW);
  }

  switch (val) {
    case 'w':  //W
      digitalWrite(leftMotorPinHigh, HIGH);
      digitalWrite(leftMotorPinLow, LOW);
      digitalWrite(rightMotorPinHigh, HIGH);
      digitalWrite(rightMotorPinLow, LOW);
      delay(delayTime);
      break;
    case 'a':   //A
      digitalWrite(leftMotorPinHigh, HIGH);
      digitalWrite(leftMotorPinLow, LOW);
      digitalWrite(rightMotorPinHigh, LOW);
      digitalWrite(rightMotorPinLow, HIGH);
      delay(delayTime);
      break;
    case 's':  //S
      digitalWrite(leftMotorPinHigh, LOW);
      digitalWrite(leftMotorPinLow, HIGH);
      digitalWrite(rightMotorPinHigh, LOW);
      digitalWrite(rightMotorPinLow, HIGH);
      delay(delayTime);
      break;
    case 'd':  //D
      digitalWrite(leftMotorPinHigh, LOW);
      digitalWrite(leftMotorPinLow, HIGH);
      digitalWrite(rightMotorPinHigh, HIGH);
      digitalWrite(rightMotorPinLow, LOW);
      delay(delayTime);
      break;
    case 'q':  //D
      digitalWrite(leftMotorPinHigh, HIGH);
      digitalWrite(leftMotorPinLow, LOW);
      delay(delayTime);
      break;
    case 'e':  //D
      digitalWrite(rightMotorPinHigh, HIGH);
      digitalWrite(rightMotorPinLow, LOW);
      delay(delayTime);
      break;
    case 'p':  //L
      if (servoPosition == 5) {
        ;
      } else {
        servoPosition = servoPosition - 5;
     
        delay(100);
      }
      laserServo.write(servoPosition);
      break;
    case 'l':  //P
      if (servoPosition == 160) {
        ;
      } else {
        servoPosition = servoPosition + 5;
        
        delay(100);
      }
      laserServo.write(servoPosition);
      break;
    case 'o':  //L
      if (servoPosition == 5) {
        ;
      } else {
        servoPosition = servoPosition - 1;
     
        delay(100);
      }
      laserServo.write(servoPosition);
      break;
    case 'k':  //P
      if (servoPosition == 160) {
        ;
      } else {
        servoPosition = servoPosition + 1;
        
        delay(100);
      }
      laserServo.write(servoPosition);
      break;
    case 32:   //Spacebar
      digitalWrite(laserPin, HIGH);
      delay(100);
      break;
    case 'x':   //1
      digitalWrite(laserPin, LOW);
      break;
    case '1':   //2
      delayTime = 0.1;
      break;
    case '2':   //2
      delayTime = 10;
      break;
    case '3':
      delayTime = 50;
      break;
    case '4':
      delayTime = 100;
      break;
  }
  
  
  if( val == 'H' || val == 'h' )               // if 'H' was received
  {
    digitalWrite(ledPin, HIGH);  // turn ON the LED
  } else { 
    digitalWrite(ledPin, LOW);   // otherwise turn it OFF
  }
  delay(100);                    // wait 100ms for next reading
} 
