#include <WebUSB.h>
#include <Servo.h>

WebUSB WebUSBSerial(1 /* https:// */, "webusb.github.io/arduino/demos/rgb");

#define WebSerial WebUSBSerial

Servo servoLeft;
Servo servoRight;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
int pos = 0;    // variable to store the servo position

int emotion[3];
int emotionIndex;

void setup() {
  while (!Serial) {
    ;
  }
  Serial.begin(9600);

  WebSerial.flush();
  emotionIndex = 0;
  //declare beginning state
  servoLeft.attach(8);
  servoLeft.write(90);
  servoRight.attach(10);
  servoRight.write(90);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  //greeting
  //send serial message to processing in order to reproduce greeting audio
  Serial.print("hello");
  servoLeft.write(0);
  delay(500);
  servoLeft.write(90);
  delay(2000);
  servoLeft.write(0);
  servoRight.write(180);
  delay(2000);
  servoLeft.write(90);
  servoRight.write(90);
  delay(3000);
  servoLeft.write(0);
  servoRight.write(180);
  delay(800);
  servoLeft.write(180);
  servoRight.write(0);
  delay(800);
  servoLeft.write(135);
  servoRight.write(90);

}

void loop() {

  if (WebSerial && WebSerial.available()) {
    
    emotion[emotionIndex++] = WebSerial.read();
    if (emotionIndex == 1) {
      if (emotion[0] == 1) {
        //happy emotion detected
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        Serial.print("h");
        //instance 1
        servoLeft.write(0);
        servoRight.write(180);
        delay(3000);
        //instance 2
        servoLeft.write(180);
        servoRight.write(45);
        delay(3000);
        //instance 3
        servoLeft.write(0);
        servoRight.write(180);
        delay(2000);
        //instance 4
        servoLeft.write(0);
        servoRight.write(0);
        delay(1000);
        //instance 5
        servoLeft.write(180);
        servoRight.write(180);
        delay(1000);
        //instance 6
        servoLeft.write(0);
        servoRight.write(0);
        delay(1000);
        //instance 7
        servoLeft.write(180);
        servoRight.write(180);
        delay(1000);
        //instance 8
        servoLeft.write(0);
        servoRight.write(0);
        delay(1000);
        //instance 9
        servoLeft.write(0);
        servoRight.write(180);
        delay(3000);
      }

      else if (emotion[0] == 2) {
        //grumpy emotion detected
        //instance 1
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(5, HIGH);
        Serial.print("g");
        servoLeft.write(180);
        servoRight.write(0);
        delay(3000);
        //instance 2
        servoLeft.write(135);
        servoRight.write(0);
        delay(3000);
        //instance 3
        servoLeft.write(0);
        servoRight.write(180);
        delay(2000);
        //instance 4
        servoLeft.write(0);
        servoRight.write(0);
        delay(1000);
        //instance 5
        servoLeft.write(180);
        servoRight.write(180);
        delay(1000);
        //instance 6
        servoLeft.write(0);
        servoRight.write(0);
        delay(1000);
        //instance 7
        servoLeft.write(180);
        servoRight.write(180);
        delay(1000);
        //instance 8
        servoLeft.write(0);
        servoRight.write(0);
        delay(1000);
        //instance 9
        servoLeft.write(0);
        servoRight.write(180);
        delay(3000);
      }
      while (WebSerial.available()) {
        int throwaway = WebSerial.read();
      }

      WebSerial.flush();
      emotionIndex = 0;
    }
  
  else {
    //normal state
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    servoLeft.write(90);
    servoRight.write(90);
    delay(5000);
  }
  //normal state wait between actions
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  servoLeft.write(90);
  servoRight.write(90);
  delay(5000);
  }

  
}
