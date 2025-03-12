# Arduino BMP Image Viewer for ST7789 TFT Screen

This Arduino project displays BMP images from a microSD card onto an ST7789 TFT screen. The images, named `1.bmp`, `2.bmp`, ..., `10.bmp`, are read from the SD card and shown one by one on the screen.

## Table of Contents
- [Features](#features)
- [Hardware Required](#hardware-required)
- [Pin Connections](#pin-connections)
  - [ST7789 TFT Screen](#st7789-tft-screen)
  - [microSD Card](#microsd-card)
- [Installation](#installation)
- [Code Overview](#code-overview)
- [Troubleshooting](#troubleshooting)
- [License](#license)
- [French Version](#version-française)

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

| Pin            | Arduino Pin | Alternate Name |
|----------------|-------------|----------------|
| **VCC**        | 5V          | VCC            |
| **GND**        | GND         | GND            |
| **CS**         | 10          | CS             |
| **RESET**      | 9           | RST, RESET     |
| **DC**         | 8           | DC             |
| **SDI (MOSI)** | 11          | SDA (MOSI)     |
| **SCK**        | 13          | SCL            |
| **BL**         | 5V          | BL             |

### microSD Card

| Pin  | Arduino Pin |
|------|-------------|
| CS   | 4           |
| SCK  | 13          |
| MOSI | 11          |
| MISO | 12          |
| VCC  | 5V          |
| GND  | GND         |

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

## Version Française

# Visionneuse d'images BMP Arduino pour écran ST7789 TFT

Ce projet Arduino affiche des images BMP à partir d'une carte microSD sur un écran ST7789 TFT. Les images, nommées `1.bmp`, `2.bmp`, ..., `10.bmp`, sont lues à partir de la carte SD et affichées une par une sur l'écran.

## Table des Matières
- [Caractéristiques](#caractéristiques)
- [Matériel Requis](#matériel-requis)
- [Connexions des Pins](#connexions-des-pins)
  - [Écran ST7789 TFT](#écran-st7789-tft)
  - [Carte microSD](#carte-microsd)
- [Installation](#installation)
- [Aperçu du Code](#aperçu-du-code)
- [Résolution des Problèmes](#résolution-des-problèmes)
- [Licence](#licence)

## Caractéristiques

- Affiche des images BMP à partir d'une carte SD.
- Charge automatiquement les images numérotées de 1 à 10 (`1.bmp`, `2.bmp`, ...).
- Chaque image est affichée pendant 2 secondes.
- Redimensionne les images pour s'adapter à l'écran ST7789 TFT (240x320).
- Installation simple et facile à utiliser.

## Matériel Requis

- **Carte Arduino** (par exemple, Arduino Uno, Nano, etc.)
- **Écran ST7789 TFT** (résolution 240x320)
- **Carte microSD** (formatée en FAT32)
- **Fils de connexion** (pour les connexions)

## Connexions des Pins

### Écran ST7789 TFT

| Pin            | Pin Arduino | Nom Alternatif |
|----------------|-------------|----------------|
| **VCC**        | 5V          | VCC            |
| **GND**        | GND         | GND            |
| **CS**         | 10          | CS             |
| **RESET**      | 9           | RST, RESET     |
| **DC**         | 8           | DC             |
| **SDI (MOSI)** | 11          | SDA (MOSI)     |
| **SCK**        | 13          | SCL            |
| **BL**         | 5V          | BL             |

### Carte microSD

| Pin  | Pin Arduino |
|------|-------------|
| CS   | 4           |
| SCK  | 13          |
| MOSI | 11          |
| MISO | 12          |
| VCC  | 5V          |
| GND  | GND         |

## Installation

1. **Installer les bibliothèques requises :**
   - `Adafruit GFX Library`
   - `Adafruit ST7789 Library`
   - `SD Library`

2. **Téléverser le code** sur votre carte Arduino.

3. **Insérer une carte microSD** dans le module SD avec des images BMP numérotées `1.bmp`, `2.bmp`, ..., placées dans le répertoire racine.

4. **Connecter le matériel** selon les connexions des pins listées ci-dessus.

## Aperçu du Code

- **Initialisation** : L'écran TFT est initialisé, et la carte SD est montée.
- **Chargement des Images** : Le programme charge les images BMP à partir de la carte SD (fichiers nommés `1.bmp`, `2.bmp`, etc.).
- **Affichage des Images** : Les images sont affichées sur l'écran TFT, redimensionnées pour s'adapter à la taille de l'écran (240x320).

## Résolution des Problèmes

- **Échec de l'initialisation de la carte SD** : Assurez-vous que la carte SD est correctement formatée (FAT32) et connectée.
- **Image non affichée** : Vérifiez que les fichiers BMP sont correctement nommés (`1.bmp`, `2.bmp`, etc.) et placés dans le répertoire racine de la carte SD.

## Licence

Ce projet est open-source et disponible sous la licence MIT.
