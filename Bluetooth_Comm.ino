#include <SoftwareSerial.h>


SoftwareSerial btSerial(A5, A4); // RX, TX pins
const int latchPin = 9;
const int clockPin = 13;
const int dataPin = 11;


void setup() {
 Serial.begin(38400);
 while (!Serial); // Wait for serial port to connect
 Serial.println("Arduino is ready!");


 btSerial.begin(9600); //Connect to BT
 btSerial.println("AT+NAMEHeart"); //Rename BT
 delay(1000);
 btSerial.println("AT+UART=9600,0,0");
 delay(1000);
 btSerial.println("AT+RESET");
 delay(1000);
 Serial.println("Bluetooth is ready!");


 pinMode(latchPin, OUTPUT);
 pinMode(clockPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
}


void loop() {
 if (btSerial.available() > 0) {
   String data = "";
   while (btSerial.available()) {
     data += (char)btSerial.read();
   }
   Serial.print("Received data: ");
   Serial.println(data);
 }
}
