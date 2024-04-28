#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUM_LEDS 35 // Change this to the number of LEDs in your ring

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{ 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0) {
    
    String receivedString = "";
    
    while (Serial.available() > 0) {
      receivedString += char(Serial.read ());
    }
    
    Serial.println(receivedString);
    
    if(receivedString == "1")
      setColor(strip.Color(0, 255, 0));  // Green
    else
      setColor(strip.Color(255, 0, 0));  // Red
    
  }

}

void setColor(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
}