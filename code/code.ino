#include <Adafruit_NeoPixel.h>

// Define the pin where the data line is connected
#define LED_PIN 4

// Define the number of LEDs in the strip
#define NUM_LEDS 16

// Create a NeoPixel object
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Wave effect settings
uint8_t maxBrightness = 255;       // Maximum brightness (0-255)
uint8_t minBrightness = 10;        // Minimum brightness to avoid complete darkness
uint16_t waveDelay = 120;           // Delay between wave steps (in milliseconds)
uint32_t waveColor = strip.Color(255, 0, 0); // Red color for the wave
uint8_t glitchProbability = 1;    // Probability (out of 100) that a glitch will occur
uint8_t glitchDuration = 20;       // Duration of glitch effect (in milliseconds)
uint8_t blackoutProbability = 1;   // Probability (out of 100) of a random blackout
uint16_t blackoutDuration = 200;   // Duration of blackout (in milliseconds)
uint8_t flickerCount = 5;          // Number of flickers during the flickering effect
uint16_t flickerDelay = 50;        // Delay between flickers (in milliseconds)

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(maxBrightness);
}

void loop() {
  // Check for random blackout
  if (random(200) < blackoutProbability) {
    blackout(); // Call the blackout function
  }
  
  waveAura(waveColor);
}

// Function to create the wave aura effect with glitch
void waveAura(uint32_t color) {
  // Clear the strip
  strip.clear();

  // Set each LED to a random brightness
  for (int i = 0; i < NUM_LEDS; i++) {
    // Generate a random brightness for each LED
    uint8_t brightness = random(minBrightness, maxBrightness);
    
    // Apply the brightness to the color
    uint32_t dimmedColor = strip.Color((brightness * 255) / maxBrightness, 0, 0);
    
    // Set the pixel color
    strip.setPixelColor(i, dimmedColor);
  }
  
  // Show the strip with the updated colors
  strip.show();
  
  // Wait before updating again to create the effect
  delay(waveDelay);
}

// Function to create a blackout effect followed by a natural flickering effect
void blackout() {
  strip.clear(); // Turn off all LEDs
  strip.show();  // Update the strip to show the blackout
  delay(blackoutDuration); // Wait for the duration of the blackout
  
  // Natural flickering effect before fully turning back on
  for (int i = 0; i < flickerCount; i++) {
    // Gradually increase brightness with random small fluctuations
    uint8_t flickerBrightness = random(minBrightness / 2, maxBrightness / 2);
    for (int j = 0; j < NUM_LEDS; j++) {
      strip.setPixelColor(j, strip.Color(flickerBrightness, 0, 0)); // Set color with varying brightness
    }
    strip.show();
    delay(flickerDelay / 2); // Faster flicker

    // Briefly turn off for a more natural effect
    strip.clear();
    strip.show();
    delay(random(flickerDelay, flickerDelay * 3)); // Randomize delay between flickers

    // Increase brightness rapidly to simulate sudden surge
    flickerBrightness = random(maxBrightness / 2, maxBrightness);
    for (int j = 0; j < NUM_LEDS; j++) {
      strip.setPixelColor(j, strip.Color(flickerBrightness, 0, 0));
    }
    strip.show();
    delay(flickerDelay / 2); // Another quick flicker
  }

  // After flickering, restore to full brightness
  strip.setBrightness(maxBrightness);
  for (int j = 0; j < NUM_LEDS; j++) {
    strip.setPixelColor(j, waveColor); // Restore the wave color to all LEDs
  }
  strip.show();
}
