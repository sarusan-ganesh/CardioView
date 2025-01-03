#include "Tlc5940.h"
#include <tlc_config.h>

int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
  for (int i = 2; i < 14; i++) { 
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW); 
  } 
  
  Tlc.init(0);
  
  Serial.begin(9600);
  Serial.println("--- Started Program ---");


  // Pin assignments for startup animation: //
  int rows[] = {
    2, 4, 5, 6, 7, 8, 12, A0
  };
  
  int cols[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
  };

  int x, i, j;
  // STARTUP ANIMATION: //
  Serial.println("Startup animation playing");
  for (int n = 0; n < 1;) {
    for (i=0; i < 14; i++) {
         for (j = 0; j < 8; j++) {
            Tlc.set(i, 4095);
            Tlc.update();
            delay(20); 
            Tlc.clear();
            digitalWrite(rows[j], HIGH);
            Serial.println(digitalRead(A2)); //0 is all the way to the right, 1 is all the way to the left/ready to start
         }
     }
     n = digitalRead(A2);
  }


}

void loop() {
  potValue = analogRead(A2);
  
  int rows[] = {
    2, 4, 5, 6, 7, 8, 12, A0
  };
  
  int cols[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
  };

  int x, i, j;

  // MATRIX ANIMATION: //
  Serial.println("Matrix animation playing");
  Serial.println(analogRead(A2)); 
  int matrix_1[8][14] = {
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  };

   int matrix_2[8][14] = {
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 1, 1,
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 1, 1,
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 1, 1,
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 1, 1,
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 1, 1,
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 1, 1,
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 1, 0, 1, 1, 0, 1, 1,
  };
  
  int matrix_3[8][14] = {
  1, 0, 1, 0, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  };
  
  for (j=0; j<14; j++) {
          Tlc.set(j, 4095);
          Tlc.update();
          delay(analogRead(A2)); // add a delay to control how long the entire 8x14 matrix displays on the screen
          Serial.println(analogRead(A2));
          Tlc.clear();
          for (i=0; i<8; i++) {
            digitalWrite (rows[i], matrix_1[i][j]);
          }
        }
  
  for (j=0; j<14; j++) {
          Tlc.set(j, 4095);
          Tlc.update();
          delay(analogRead(A2)); // add a delay to control how long the entire 8x14 matrix displays on the screen
          Serial.println(analogRead(A2));
          Tlc.clear();
          for (i=0; i<8; i++) {
            digitalWrite (rows[i], matrix_2[i][j]);
          }
        }
  
  for (j=0; j<14; j++) {
          Tlc.set(j, 4095);
          Tlc.update();
          delay(analogRead(A2)); // add a delay to control how long the entire 8x14 matrix displays on the screen
          Serial.println(analogRead(A2));
          Tlc.clear();
          for (i=0; i<8; i++) {
            digitalWrite (rows[i], matrix_3[i][j]);
          }
        }
 
//  // RESET EVERYTHING TO OFF //
//  Serial.println("Turning everything off");
//  Serial.println(analogRead(A2)); 
//  Tlc.clear();
//  for (int i = 0; i<8; i++) {
//    digitalWrite(rows[i], 0); //set all rows to 0
//  }
//  Tlc.update();
//  delay(2000);
 }
