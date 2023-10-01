#  Display gravatational forces by Axis within a spi screen on the arduino Nano with ADXL345 Accelerometer 
Arduino Nano &amp; ADXL345 &amp; TFT Screen

![Screenshot_20231001_192410_Gallery](https://github.com/Jekyllz/adxl345tft/assets/24834166/e12f21d6-a370-4804-be30-0a793e261e89)


Libraries Needed -
* [Adafruit_GFX.h](https://learn.adafruit.com/adafruit-gfx-graphics-library/overview)    // Core graphics library
* [Adafruit_ST7789.h](https://github.com/adafruit/Adafruit-ST7735-Library/blob/master/Adafruit_ST7789.h) // Hardware-specific library for ST7789
* SPI.h // installed by default
* [Wire.h](https://www.arduino.cc/reference/en/language/functions/communication/wire/)  // Wire library - used for I2C communication


Parts Needed
[ADXL354](https://thepihut.com/products/adafruit-adxl345-triple-axis-accelerometer-2g-4g-8g-16g-w-i2c-spi) 
[Arduino Nano](https://thepihut.com/products/arduino-nano-every-with-headers?variant=32106484629566&currency=GBP&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&gclid=CjwKCAjwseSoBhBXEiwA9iZtxnuM0qERpxCSpG5IbdN6cRTzkA41e3vpNDruZOq5qbsoFs6sOWkMMRoCI2wQAvD_BwE)
[SPI Screen 1.14](https://www.amazon.co.uk/240x135-Display-Module-ST7789-Arduino/dp/B09PZGDR1Z)


## Wiring 
 ADXL
* SCL = A5
* SDA = A4
* VCC = V5
* GND = GND

 1.14' Screen
* CS = D10
* RES = D9
* DC = D8
* SDA = D11
* SCL = D13
* VCC = 3v3
* GND = GND

Within Main.ino Line 47 - The three Axis Transmissions are to set the calabration of the ADXL345 - 
In order to calculate if the ADXL is not displaying correctly - you can follow instructions here:

see - [ADXL345 Accelerometer Calibration](https://howtomechatronics.com/tutorials/arduino/how-to-track-orientation-with-arduino-and-adxl345-accelerometer/#:~:text=and%20D0%20bits.-,ADXL345%20Accelerometer%20Calibration,-Nevertheless%2C%20once%20we)
