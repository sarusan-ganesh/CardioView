#include "Tlc5940.h"
#include <tlc_config.h>
#include <Arduino.h>

const int MATRIX_ROWS = 8;
const int MATRIX_COLS = 14;
const int MATRIX_LIST_SIZE = 3;
String receivedStrings[MATRIX_LIST_SIZE];
int receivedMatrices[MATRIX_LIST_SIZE][MATRIX_COLS][MATRIX_ROWS];

void setup() {
  Serial.begin(9600);
  Tlc.init();
  Tlc.clear();
  Tlc.update();
}

void loop() {
  static int matricesReceived = 0;

    if (Serial.available() == 0) {
Serial.println("no serial");
    }
    
  if (Serial.available() > 0) {
    String receivedString = Serial.readStringUntil('\n');
    receivedStrings[matricesReceived] = receivedString;
    matricesReceived++;

    if (matricesReceived == MATRIX_LIST_SIZE) {
      for (int i = 0; i < MATRIX_LIST_SIZE; i++) {
        String receivedString = receivedStrings[i];
        int index = 0;
        for (int col = 0; col < MATRIX_COLS; col++) {
          for (int row = 0; row < MATRIX_ROWS; row++) {
            receivedMatrices[i][col][row] = receivedString.charAt(index) - '0';
            index++;
          }
        }
      }
      printMatrices(receivedMatrices, MATRIX_LIST_SIZE);
      displayMatrix(receivedMatrices[MATRIX_LIST_SIZE - 1]);
      matricesReceived = 0;
    }
  }
}

void printMatrices(int matrices[][MATRIX_COLS][MATRIX_ROWS], int numMatrices) {
  for (int k = 0; k < numMatrices; k++) {
    Serial.println("Received matrix:");
    for (int i = 0; i < MATRIX_COLS; i++) {
      for (int j = 0; j < MATRIX_ROWS; j++) {
        Serial.print(matrices[k][i][j]);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
}

void displayMatrix(int matrix[][MATRIX_ROWS]) {
  for (int row = 0; row < MATRIX_ROWS; row++) {
    for (int col = 0; col < MATRIX_COLS; col++) {
      int tlcIndex = row * MATRIX_COLS + col;
      Tlc.set(tlcIndex, matrix[col][row] * 4095);
    }
  }
  Tlc.update();
  delay(20); // Wait for a short time to allow the LEDs to update
}
