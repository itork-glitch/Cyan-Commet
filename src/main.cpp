#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 60
#define BRIGHTNESS 255

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    strip.begin();
    strip.setBrightness(BRIGHTNESS);
}

void loop()
{
    for (int i = LED_COUNT - 1; i >= 0; i--) {
        for (int j = 0; j < LED_COUNT; j++) {
            int brightness = map((j + i) % LED_COUNT, 0, LED_COUNT / 2, 0, 255);
            brightness = constrain(brightness, 0, 255);
            if ((j + i) % LED_COUNT >= LED_COUNT / 2) {
                strip.setPixelColor(j, strip.Color(0, 0, 0));
            } else {
                strip.setPixelColor(j, strip.Color(0, brightness, brightness));
            }
        }
        strip.show();
        delay(30);
    }
}