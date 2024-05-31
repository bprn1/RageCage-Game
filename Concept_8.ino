#include <Adafruit_CircuitPlayground.h>
float sound;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop() {
  sound = CircuitPlayground.mic.soundPressureLevel(500);
  Serial.println(sound);
  if(sound < 63) {
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 50, 180, 0);
  } else if (sound < 75) {
    CircuitPlayground.setPixelColor(3, 150, 150, 0);
    CircuitPlayground.setPixelColor(4, 180, 60, 0);
    CircuitPlayground.setPixelColor(5, 180, 60, 0);
  } else if (sound < 87) {
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
  } else if (sound < 105) {
    CircuitPlayground.setPixelColor(8, 150, 0, 190);
    CircuitPlayground.setPixelColor(9, 0, 0, 255);
  } else {
    for(int i = 0; i< 10; i++) {
      CircuitPlayground.clearPixels();
      int randR = random(235);
      int randG = random(235);
      int randB = random(235);
      CircuitPlayground.setPixelColor(i,   randR,   randG,   randB);
      delay(80);
    }
  }

  delay(500);
  CircuitPlayground.clearPixels();
}
