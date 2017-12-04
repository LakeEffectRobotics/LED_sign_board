#include "FastLED.h"

#define NUM_LEDS 50
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.show();
}

void loop() {
  redPurpleCycle(50);
}

void redPurpleCycle(int wait) {
  int i, j;

  for (j = 0; j < NUM_LEDS; j++) {
    for (i = 0; i < NUM_LEDS; i++) {
      int x=(i+j) % NUM_LEDS;
      if (x>=NUM_LEDS/2)
        x=NUM_LEDS-1-x;
      x=255*x/(NUM_LEDS/2-1);
      leds[i] = CRGB(160,0,x);
    }
    FastLED.show();
    delay(wait);
  }
}

