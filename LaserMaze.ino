//Made by Justin Nguyen
//For use by Texas Panic Room
//9/21/17

#include <NewTone.h>

//Pinout
const byte photo0 = 2;
const byte photo1 = 3;
const byte photo2 = 4;
const byte photo3 = 5;
const byte photo4 = 6;
const byte photo5 = 7;
const byte photo6 = 8;
const byte photo7 = 9;
const byte photo8 = 10;
const byte photo9 = 11;
const byte photo10 = 12;
const byte photo11 = A0;
const byte buzzer = A1;
const byte stopper = A5;

//Input Values
bool photoV0;
bool photoV1;
bool photoV2;
bool photoV3;
bool photoV4;
bool photoV5;
bool photoV6;
bool photoV7;
bool photoV8;
bool photoV9;
bool photoV10;
bool photoV11;

//State and Input Tracking
byte photos[12];
bool photoVs[12];
int photosLen, photoVsLen;
unsigned long buzzerDuration;
unsigned int frequency;

void setup() {
  Serial.begin(9600);
  Serial.println("Laser Maze");

  photos[0] = photo0;
  photos[1] = photo1;
  photos[2] = photo2;
  photos[3] = photo3;
  photos[4] = photo4;
  photos[5] = photo5;
  photos[6] = photo6;
  photos[7] = photo7;
  photos[8] = photo8;
  photos[9] = photo9;
  photos[10] = photo10;
  photos[11] = photo11;

  photoVs[0] = photoV0;
  photoVs[1] = photoV1;
  photoVs[2] = photoV2;
  photoVs[3] = photoV3;
  photoVs[4] = photoV4;
  photoVs[5] = photoV5;
  photoVs[6] = photoV6;
  photoVs[7] = photoV7;
  photoVs[8] = photoV8;
  photoVs[9] = photoV9;
  photoVs[10] = photoV10;
  photoVs[11] = photoV11;

  photosLen = sizeof(photos)/sizeof(photos[0]);
  photoVsLen = sizeof(photoVs)/sizeof(photoVs[0]);

  buzzerDuration = 2000;
  frequency = 1000;
  
  for (int a = 0; a < photosLen; a++){
    pinMode(photos[a], INPUT);
  }
  
}

void loop() {
  for (int i = 0; i < photoVsLen; i++){
      photoVs[i] = digitalRead(photos[i]);
      if (!photoVs[i]){
        Serial.println(i);
        buzz();
      }
    }
}

void buzz() {
   NewTone(buzzer, frequency, buzzerDuration);
}

