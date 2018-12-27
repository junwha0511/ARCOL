 

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.

#include <Adafruit_GFX.h>

#include "Adafruit_LEDBackpack.h"

 

Adafruit_7segment matrix = Adafruit_7segment();

 

int echoPin = 12;

int trigPin= 13;

int score = 0;

void setup() {

#ifndef __AVR_ATtiny85__

  Serial.begin(9600);

  Serial.println("7 Segment Backpack Test");

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  

#endif

  matrix.begin(0x70);

  matrix.writeDigitNum(0, score);

  matrix.writeDisplay();

}

 

void loop() {

  float duration, distance;

 

  digitalWrite(trigPin, HIGH);

  delay(10);

  digitalWrite(trigPin, LOW);

 

  duration = pulseIn(echoPin, HIGH);

  distance = ((float)(340 * duration) / 1000) / 2;

 

  if (distance <= 90) {

    score +=1;

    if(score<=9){

      matrix.writeDigitNum(0, score);

      matrix.writeDisplay(); 

    }else if(score>9){

      matrix.writeDigitNum(0, (int)(score/10));

      matrix.writeDigitNum(1, score%10);

      matrix.writeDisplay();

    }

    delay(500);

  }

 

   delay(50);

}