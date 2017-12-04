#include "FastLED.h"

#define NUM_LEDS 100
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  rainbowCycle(20);
}

void rainbowCycle(int wait) {
  int i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles
    for (i = 0; i < NUM_LEDS; i++) {
      int x=j % 256;
      if (x>128)x=256-x;
      leds[i] = CRGB(x,0,128-x);
    }
    FastLED.show();
    delay(wait);
  }
}

