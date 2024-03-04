/*
 * MoxieBoard.ino
 * 
 * Pete Prodoehl <pete@2xlnetworks.com>
 * 
 * Terrible code! But it works, so, yeah...
 * 
 */

#include <Bounce.h>
#include <EEPROM.h>


// Your SD must be formatted FAT16/FAT32.
//
// Set USE_SD_H nonzero to use SD.h.
// Set USE_SD_H zero to use SdFs.h.
//
#define USE_SD_H 1
//
#if USE_SD_H
#include <SD.h>
#else  // USE_SD_H
#include "SdFs.h"
SdFat SD;
#endif  // USE_SD_H

// Modify SD_CS_PIN for your board.
// For Teensy 3.6 and SdFs.h use BUILTIN_SDCARD.
#define SD_CS_PIN BUILTIN_SDCARD

File myFile;

Bounce button1 = Bounce(1, 25);
Bounce button2 = Bounce(2, 25);
Bounce button3 = Bounce(3, 25);
Bounce button4 = Bounce(4, 25);
Bounce button5 = Bounce(5, 25);
Bounce button6 = Bounce(6, 25);
Bounce button7 = Bounce(7, 25);
Bounce button8 = Bounce(8, 25);
Bounce button9 = Bounce(9, 25);
Bounce button10 = Bounce(10, 25);
Bounce button11 = Bounce(11, 25);
Bounce button12 = Bounce(12, 25);
Bounce button13 = Bounce(14, 25);
Bounce button14 = Bounce(15, 25);
Bounce button15 = Bounce(16, 25);
Bounce button16 = Bounce(17, 25);
Bounce button17 = Bounce(18, 25);
Bounce button18 = Bounce(19, 25);
Bounce button19 = Bounce(20, 25);
Bounce button20 = Bounce(21, 25);
Bounce button21 = Bounce(22, 25);
Bounce button22 = Bounce(23, 25);
Bounce button23 = Bounce(33, 25);
Bounce button24 = Bounce(34, 25);

int vote01 = 0;
int vote02 = 0;
int vote03 = 0;
int vote04 = 0;
int vote05 = 0;
int vote06 = 0;
int vote07 = 0;
int vote08 = 0;
int vote09 = 0;
int vote10 = 0;
int vote11 = 0;
int vote12 = 0;
int vote13 = 0;
int vote14 = 0;
int vote15 = 0;
int vote16 = 0;
int vote17 = 0;
int vote18 = 0;
int vote19 = 0;
int vote20 = 0;
int vote21 = 0;
int vote22 = 0;
int vote23 = 0;
int vote24 = 0;

int votesTotal[24];

int killjoy = 999; // nearly one second for the delay

int pressed = 0;

void writeUnsignedIntIntoEEPROM(int address, unsigned int number)
{ 
  EEPROM.write(address, number >> 8);
  EEPROM.write(address + 1, number & 0xFF);
}
unsigned int readUnsignedIntFromEEPROM(int address)
{
  return (EEPROM.read(address) << 8) + EEPROM.read(address + 1);
}

void setup() {
  Serial.begin(9600);
  // while (!Serial) {}

  #if USE_SD_H
    Serial.println(F("Using SD.h"));
  #else  // USE_SD_H
    Serial.println(F("Using SdFs.h"));  
  #endif  // USE_SD_H

/*
  while (!Serial.available()) {
    yield();
  }
  */
  Serial.print("Preparing SD card...");

  
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("Preparing card failed!");
    return;
  }
  Serial.println("Preparing card done.");



  pinMode(1,  INPUT_PULLUP);
  pinMode(2,  INPUT_PULLUP);
  pinMode(3,  INPUT_PULLUP);
  pinMode(4,  INPUT_PULLUP);
  pinMode(5,  INPUT_PULLUP);
  pinMode(6,  INPUT_PULLUP);
  pinMode(7,  INPUT_PULLUP);
  pinMode(8,  INPUT_PULLUP);
  pinMode(9,  INPUT_PULLUP);
  pinMode(10,  INPUT_PULLUP);
  pinMode(11,  INPUT_PULLUP);
  pinMode(12,  INPUT_PULLUP);
  pinMode(14,  INPUT_PULLUP);
  pinMode(15,  INPUT_PULLUP);
  pinMode(16,  INPUT_PULLUP);
  pinMode(17,  INPUT_PULLUP);
  pinMode(18,  INPUT_PULLUP);
  pinMode(19,  INPUT_PULLUP);
  pinMode(20,  INPUT_PULLUP);
  pinMode(21,  INPUT_PULLUP);
  pinMode(22,  INPUT_PULLUP);
  pinMode(23,  INPUT_PULLUP);
  pinMode(33,  INPUT_PULLUP);
  pinMode(34,  INPUT_PULLUP);

  
  // if the file opened okay, write to it:
  digitalWrite(13, LOW);
  if (SD.exists("MOXIE.csv")) 
  {
    for(int i =0; i <24; i++){
      votesTotal[i] = readUnsignedIntFromEEPROM(i*2);
    }    
  }else{

    for(int i =0; i <24; i++){
      writeUnsignedIntIntoEEPROM(i*2,0);
    }
  }


  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}


void loop() {

  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();
  button12.update();
  button13.update();
  button14.update();
  button15.update();
  button16.update();
  button17.update();
  button18.update();
  button19.update();
  button20.update();
  button21.update();
  button22.update();
  button23.update();
  button24.update();
  

  if (button1.fallingEdge()) {
   votesTotal[0]++;
   pressed = 1; 
  }

  if (button2.fallingEdge()) {
   votesTotal[1]++;
   pressed = 1; 
  }

  if (button3.fallingEdge()) {
   votesTotal[2]++;
   pressed = 1; 
  }

  if (button4.fallingEdge()) {
   votesTotal[3]++;
   pressed = 1; 
  }

  if (button5.fallingEdge()) {
   votesTotal[4]++;
   pressed = 1; 
  }

  if (button6.fallingEdge()) {
   votesTotal[5]++;
   pressed = 1; 
  }

  if (button7.fallingEdge()) {
   votesTotal[6]++;
   pressed = 1; 
  }

  if (button8.fallingEdge()) {
   votesTotal[7]++;
   pressed = 1; 
  }
 
  if (button9.fallingEdge()) {
   votesTotal[8]++;
   pressed = 1; 
  }
 
  if (button10.fallingEdge()) {
   votesTotal[9]++;
   pressed = 1; 
  }
 
  if (button11.fallingEdge()) {
   votesTotal[10]++;
   pressed = 1; 
  }
 
  if (button12.fallingEdge()) {
   votesTotal[11]++;
   pressed = 1; 
  }
 
  if (button13.fallingEdge()) {
   votesTotal[12]++;
   pressed = 1; 
  }
 
  if (button14.fallingEdge()) {
   votesTotal[13]++;
   pressed = 1; 
  }
   
  if (button15.fallingEdge()) {
   votesTotal[14]++;
   pressed = 1; 
  }

  if (button16.fallingEdge()) {
   votesTotal[15]++;
   pressed = 1; 
  }
  
  if (button17.fallingEdge()) {
   votesTotal[16]++;
   pressed = 1; 
  }
 
  if (button18.fallingEdge()) {
   votesTotal[7]++;
   pressed = 1; 
  }
 
  if (button19.fallingEdge()) {
   votesTotal[18]++;
   pressed = 1; 
  }
 
  if (button20.fallingEdge()) {
   votesTotal[19]++;
   pressed = 1; 
  }
 
  if (button21.fallingEdge()) {
   votesTotal[20]++;
   pressed = 1; 
  }
 
  if (button22.fallingEdge()) {
   votesTotal[21]++;
   pressed = 1; 
  }
 
  if (button23.fallingEdge()) {
   votesTotal[22]++;
   pressed = 1; 
  }
 
  if (button24.fallingEdge()) {
   votesTotal[23]++;
   pressed = 1; 
  }

  
  if (pressed > 0) {
   
  /*
   * WRITE
   *
   */
   
  // open the file
  SD.remove("MOXIE.csv");
  myFile = SD.open("MOXIE.csv", FILE_WRITE);
  // if the file opened okay, write to it:
  digitalWrite(13, LOW);
  if (myFile) {
    myFile.print("vote01,vote02,vote03,vote04,vote05,vote06,vote07,vote08,vote09,vote10,vote11,vote12,vote13,vote14,vote15,vote16,vote17,vote18,vote19,vote20,vote21,vote22,vote23,vote24");
    myFile.println(""); // end of line

    for (int i = 0; i < 24; i++) {
      Serial.print(votesTotal[i]);
      Serial.print(",");
      myFile.print(votesTotal[i]);
      myFile.print(",");

      writeUnsignedIntIntoEEPROM(i*2,votesTotal[i]);
    }
    
    Serial.println(""); // end of line
    
    myFile.println(""); // end of line
    // close the file:
    // When you use file.write(), it doesn't write to the card until you flush() or close(). 
    // Whenever you open a file, be sure to close it to save your data. 
    myFile.close();
    //Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening MOXIE.csv");
  }
  
  pressed = 0;

  delay(killjoy);
  digitalWrite(13, HIGH);
    
  }

  
}
