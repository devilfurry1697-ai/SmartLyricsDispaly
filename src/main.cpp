#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 5

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
    8, 8, LED_PIN,
    NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
    NEO_GRB + NEO_KHZ800
);

String lyrics = "HELLO MUSIC";

void setup() {
    matrix.begin();
    matrix.setBrightness(80);
    matrix.setTextWrap(false);
    matrix.setTextColor(matrix.Color(0, 255, 0));
}

void loop() {
    for (int x = 8; x >= -(lyrics.length() * 6); x--) {
        matrix.fillScreen(0);
        matrix.setCursor(x, 0);
        matrix.print(lyrics);
        matrix.show();
        delay(100);
    }
}