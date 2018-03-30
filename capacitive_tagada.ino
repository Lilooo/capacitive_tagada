#include <CapacitiveSensor.h> //CapitiveSense Library Paul Badger 2008. Changes and additions to code were made by Alan Waldock, March 2014.
#include <Adafruit_NeoPixel.h>
        
#define PIN1 10
#define NUMPIXELS1 1
#define PIN2 11
#define NUMPIXELS2 1
#define PIN3 12
#define NUMPIXELS3 1

int touch1 = 0;
int touch2 = 0;
int touch3 = 0;

long newtotal1 = 0;
long oldtotal1 = 0;
long newtotal2 = 0;
long oldtotal2 = 0;
long newtotal3 = 0;
long oldtotal3 = 0;

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); 
CapacitiveSensor cs_4_6 = CapacitiveSensor(4,6);       
CapacitiveSensor cs_4_8 = CapacitiveSensor(4,8);

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip1.show();
  strip2.show();
  strip3.show(); 
}

void loop()
{
  long start = millis();
  newtotal1 = cs_4_2.capacitiveSensor(30);
  newtotal2 = cs_4_6.capacitiveSensor(30);
  newtotal3 = cs_4_8.capacitiveSensor(30);
  
  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

  Serial.print(newtotal1);                  // print sensor output 1
  Serial.print("\t");
  Serial.print(newtotal2);                  // print sensor output 2
  Serial.print("\t");
  Serial.println(newtotal3);                // print sensor output 3

  delay(10);                             // arbitrary delay to limit data to serial port 

  long diff1 = newtotal1 - oldtotal1;
  long diff2 = newtotal2 - oldtotal2;
  long diff3 = newtotal3 - oldtotal3;
  
  if (newtotal1 != 0 && diff1 > 10) {
    touch1++;
    if (touch1 == 1) {
      for(int i=0;i<NUMPIXELS1;i++){
        strip1.setPixelColor(i, strip1.Color(0,150,0));
      }
    }
    if (touch1 == 2) {
      for(int i=0;i<NUMPIXELS1;i++){
        strip1.setPixelColor(i, strip1.Color(150,0,0));
      }
    }
    if (touch1 == 3) {
      for(int i=0;i<NUMPIXELS1;i++){
        strip1.setPixelColor(i, strip1.Color(0,0,150));
      }
    }
    if (touch1 == 4 ) {
      for(int i=0;i<NUMPIXELS1;i++){
        strip1.setPixelColor(i, strip1.Color(0,0,0));
      }
      touch1 = 0;
    }
  }
  strip1.show(); 

  if (newtotal2 != 0 && diff2 > 10) {
    touch2++;
    if (touch2 == 1) {
      for(int i=0;i<NUMPIXELS2;i++){
        strip2.setPixelColor(i, strip2.Color(0,150,0));
      }
    }
    if (touch2 == 2) {
      for(int i=0;i<NUMPIXELS2;i++){
        strip2.setPixelColor(i, strip2.Color(150,0,0));
      }
    }
    if (touch2 == 3) {
      for(int i=0;i<NUMPIXELS2;i++){
        strip2.setPixelColor(i, strip2.Color(0,0,150));
      }
    }
    if (touch2 == 4 ) {
      for(int i=0;i<NUMPIXELS2;i++){
        strip2.setPixelColor(i, strip2.Color(0,0,0));
      }
      touch2 = 0;
    }
  }
  strip2.show(); 

  if (newtotal3 != 0 && diff3 > 10) {
    touch3++;
    if (touch3 == 1) {
      for(int i=0;i<NUMPIXELS3;i++){
        strip3.setPixelColor(i, strip3.Color(0,150,0));
      }
    }
    if (touch3 == 2) {
      for(int i=0;i<NUMPIXELS3;i++){
        strip3.setPixelColor(i, strip3.Color(150,0,0));
      }
    }
    if (touch3 == 3) {
      for(int i=0;i<NUMPIXELS3;i++){
        strip3.setPixelColor(i, strip3.Color(0,0,150));
      }
    }
    if (touch3 == 4 ) {
      for(int i=0;i<NUMPIXELS3;i++){
        strip3.setPixelColor(i, strip3.Color(0,0,0));
      }
      touch3 = 0;
    }
  }
  strip3.show();

  oldtotal1 = newtotal1;
  oldtotal2 = newtotal2;
  oldtotal3 = newtotal3;

  
  delay(100);
  
}
