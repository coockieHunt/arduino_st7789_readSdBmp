# Arduino BMP Image Viewer for ST7789 TFT Screen

This Arduino project displays BMP images from a microSD card onto an ST7789 TFT screen. The images, named `1.bmp`, `2.bmp`, ..., `10.bmp`, are read from the SD card and shown one by one on the screen. Each image is displayed for 2 seconds before the next one is shown. The screen is initialized with a white background, and the images are resized to fit the screen resolution.

## Features

- Displays BMP images from an SD card.
- Automatically loads images numbered from 1 to 10 (`1.bmp`, `2.bmp`, ...).
- Each image is displayed for 2 seconds.
- Resizes images to fit the ST7789 TFT screen (240x320).
- Simple setup and easy-to-use.

## Hardware Required

- **Arduino Board** (e.g., Arduino Uno, Nano, etc.)
- **ST7789 TFT Screen** (240x320 resolution)
- **microSD Card** (formatted with FAT32)
- **Jumper wires** (for connections)

## Pin Connections

### ST7789 TFT Screen

| Pin        | Arduino Pin |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| CS         | 10          |
| RESET      | 9           |
| DC         | 8           |
| SDI(MOSI)  | 11          |
| SCK        | 13          |

### microSD Card

| Pin        | Arduino Pin |
|------------|-------------|
| CS         | 4           |
| SCK        | 13          |
| MOSI       | 11          |
| MISO       | 12          |
| VCC        | 5V          |
| GND        | GND         |

## Installation

1. **Install the required libraries:**
   - `Adafruit GFX Library`
   - `Adafruit ST7789 Library`
   - `SD Library`

2. **Upload the code** to your Arduino board.

3. **Insert a microSD card** into the SD card module with BMP images numbered `1.bmp`, `2.bmp`, ..., placed in the root directory.

4. **Connect the hardware** according to the pin connections listed above.

## Code Overview

- **Initialization**: The TFT screen is initialized, and the SD card is mounted.
- **Image Loading**: The program loads BMP images from the SD card (files named `1.bmp`, `2.bmp`, etc.).
- **Image Display**: The images are displayed on the TFT screen, resized to fit the screen size (240x320).

## Troubleshooting

- **SD card initialization failed**: Ensure the SD card is properly formatted (FAT32) and connected.
- **Image not displayed**: Check if the BMP files are properly named (`1.bmp`, `2.bmp`, etc.) and placed in the root directory of the SD card.

## License

This project is open-source and available under the MIT License.
