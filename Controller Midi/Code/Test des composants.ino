#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


Adafruit_NeoPixel strip_case = Adafruit_NeoPixel(37, 8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_bleft = Adafruit_NeoPixel(9, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_bmid = Adafruit_NeoPixel(9, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_bright = Adafruit_NeoPixel(9, 4, NEO_GRB + NEO_KHZ800);

int analogPin1 = A0;
int analogPin2 = A1;
int analogPin3 = A2;


void setup() {
  Serial.begin(9600);
  strip_case.setBrightness(80);
  strip_case.begin();
  strip_bleft.setBrightness(80);
  strip_bleft.begin();
  strip_bmid.setBrightness(80);
  strip_bmid.begin();
  strip_bright.setBrightness(80);
  strip_bright.begin();
}

void loop() {
  
  chase(strip_bright.Color(66, 245, 164));
  chaseM(strip_bmid.Color(66, 245, 164));
  chaseL(strip_bleft.Color(66, 245, 164));
  chaseC(strip_case.Color(66, 245, 164));
  
  // colorWipe(strip.Color(255, 0, 0), 50); // Red
  // colorWipe(strip.Color(0, 255, 0), 50); // Green
  // colorWipe(strip.Color(0, 0, 255), 50); // Blue
  // colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  // theaterChase(strip.Color(127, 127, 127), 50); // White
  // theaterChase(strip.Color(127, 0, 0), 50); // Red
  // theaterChase(strip.Color(0, 0, 127), 50); // Blue
  // rainbowCycle(20);
  // theaterChaseRainbow(50);
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip_bright.numPixels()+4; i++) {
      strip_bright.setPixelColor(i  , c); // Affiche une nouvelle pixel
      strip_bright.setPixelColor(i-4, 0); // Efface une pixel 
      strip_bright.show();
      delay(25);
  }
}


static void chaseM(uint32_t c) {
  for(uint16_t i=0; i<strip_bmid.numPixels()+4; i++) {
      strip_bmid.setPixelColor(i  , c); // Affiche une nouvelle pixel
      strip_bmid.setPixelColor(i-4, 0); // Efface une pixel 
      strip_bmid.show();
      delay(25);
  }
}

static void chaseL(uint32_t c) {
  for(uint16_t i=0; i<strip_bleft.numPixels()+4; i++) {
      strip_bleft.setPixelColor(i  , c); // Affiche une nouvelle pixel
      strip_bleft.setPixelColor(i-4, 0); // Efface une pixel 
      strip_bleft.show();
      delay(25);
  }
}

static void chaseC(uint32_t c) {
  for(uint16_t i=0; i<strip_case.numPixels()+4; i++) {
      strip_case.setPixelColor(i  , c); // Affiche une nouvelle pixel
      strip_case.setPixelColor(i-4, 0); // Efface une pixel 
      strip_case.show();
      delay(25);
  }
}
