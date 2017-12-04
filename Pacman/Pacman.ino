#include "FastLED.h"

#define NUM_LEDS 100
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

// Function to reverse every second row of LEDs, as in the sign board:
int serpentine(int i) {
  int r=i/10;
  int c=i%10;
  if ((r%2)==1)
    c=9-c;
  return 10*r+c;
}

// Define single colour patterns:
int pacman1[]={ 0,0,0,1,1,1,1,0,0,0,
                0,0,1,1,1,1,1,1,0,0,
                0,1,1,1,1,1,1,1,1,0,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                0,1,1,1,1,1,1,1,1,0,
                0,0,1,1,1,1,1,1,0,0,
                0,0,0,1,1,1,1,0,0,0};

int pacman2[]={ 0,0,0,1,1,1,1,0,0,0,
                0,0,1,1,1,1,1,1,0,0,
                0,1,1,1,1,1,1,1,1,0,
                1,1,1,1,1,1,1,1,0,0,
                1,1,1,1,1,1,0,0,0,0,
                1,1,1,1,1,0,0,0,0,0,
                1,1,1,1,1,1,1,0,0,0,
                0,1,1,1,1,1,1,1,1,0,
                0,0,1,1,1,1,1,1,0,0,
                0,0,0,1,1,1,1,0,0,0};

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[serpentine(i)] = CRGB(pacman1[i]*255,pacman1[i]*175,0);
    }
    FastLED.show();
    delay(1000);
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[serpentine(i)] = CRGB(pacman2[i]*255,pacman2[i]*175,0);
    }
    FastLED.show();
    delay(1000);
}

