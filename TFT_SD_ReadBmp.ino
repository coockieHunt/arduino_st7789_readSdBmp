/*
    author: ck_hunt (https://github.com/coockieHunt)
    v: 1.0.0
    Pin Connections:
        TFT Screen (ST7789):
            - CS (Chip Select): Pin 10
            - RST (Reset): Pin 9
            - DC (Data/Command): Pin 8
      
        SD Card:
            - CS (Chip Select): Pin 4
    
    Utility:
        - This code initializes an ST7789 display and a microSD card. 
        - It reads BMP images (named 1.bmp, 2.bmp, ..., 10.bmp) from the SD card
          and displays them one by one on the screen. Each image is shown for 2 seconds.
        - The screen orientation is set, and the screen is filled with a white background
          before each image is displayed.
    
    Required Libraries:
        - SPI
        - SD
        - Adafruit_GFX
        - Adafruit_ST7789
*/

#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8
#define SD_CS      4

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

File bmpFile;

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ;
    }

    Serial.print("Initializing SD card...");
    if (!SD.begin(SD_CS)) {
        Serial.println("Failed!");
        while (1);
    }
    Serial.println("SD card initialized.");

    tft.init(240, 320);
    tft.setRotation(3);
    tft.fillScreen(ST77XX_WHITE);

    for (int i = 1; i <= 10; i++) {
        char filename[20];
        snprintf(filename, sizeof(filename), "%d.bmp", i);
        
        bmpFile = SD.open(filename);
        
        if (bmpFile) {
            Serial.print("Reading ");
            Serial.println(filename);
            
            drawBMP(0, 0, filename);
            delay(2000);
            
            bmpFile.close();
        } else {
            Serial.print("Failed to open ");
            Serial.println(filename);
        }
    }
}

void loop() {
}

void drawBMP(int x, int y, char* filename) {
    bmpFile = SD.open(filename);
    if (!bmpFile) {
        Serial.println("Failed to open image.");
        return;
    }

    uint8_t header[54];
    bmpFile.read(header, 54);

    if (header[0] != 'B' || header[1] != 'M') {
        Serial.println("Not a valid BMP file.");
        bmpFile.close();
        return;
    }

    uint32_t width = *(uint32_t*)&header[18];
    uint32_t height = *(uint32_t*)&header[22];
    uint32_t rowSize = (width * 3 + 3) & ~3;

    float xRatio = 240.0 / width;
    float yRatio = 320.0 / height;

    for (int row = 0; row < 320; row++) {
        for (int col = 0; col < 240; col++) {
            int xImage = col / xRatio;
            int yImage = row / yRatio;

            if (xImage < width && yImage < height) {
                uint8_t pixel[3];
                bmpFile.seek(54 + yImage * rowSize + xImage * 3);
                bmpFile.read(pixel, 3);

                uint16_t color = tft.color565(pixel[2], pixel[1], pixel[0]);
                tft.drawPixel(col, row, color);
            }
        }
    }

    bmpFile.close();
}
