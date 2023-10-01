
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <Wire.h>  // Wire library - used for I2C communication

int ADXL345 = 0x53; // The ADXL345 sensor I2C address

float X_out, Y_out, Z_out;  // Outputs

#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

#define TFT_CS 10 // if your display has CS pin
#define TFT_RST 9 // reset pin
#define TFT_DC 8 // data pin
#define TFT_MOSI 11
#define TFT_SCLK 13

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


void setup() {
  // Use this initializer (uncomment) if using a 1.3" or 1.54" 240x240 TFT:
  tft.init(135, 240, SPI_MODE3);           // Init ST7789 240x240
  tft.setRotation(0);
  // put your setup code here, to run once:
  //tftPrintTest();

  //testfastlines(ST77XX_RED, ST77XX_BLUE);

    Serial.begin(9600); // Initiate serial communication for printing the results on the Serial monitor
  Wire.begin(); // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345); // Start communicating with the device 
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8); // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable 
  Wire.endTransmission();


  Wire.beginTransmission(ADXL345);
  Wire.write(0x1E);  // X-axis offset register
  Wire.write(246);
  Wire.endTransmission();
  delay(10);

  //Y-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1F); // Y-axis offset register
  Wire.write(-2);
  Wire.endTransmission();
  delay(10);
  
  //Z-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x20); // Z-axis offset register
  Wire.write(-7);
  Wire.endTransmission();
  delay(10);
  // This code goes in the SETUP section
// Off-set Calibration
  //X-axis
}



void loop() {
  testlines(ST77XX_BLACK);
// put your main code here, to run repeatedly:

  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  X_out = X_out/256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  Y_out = Y_out/256;
  Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  Z_out = Z_out/256;

  Serial.print("Xa= ");
  Serial.print(X_out);
  Serial.print("   Ya= ");
  Serial.print(Y_out);
  Serial.print("   Za= ");
  Serial.println(Z_out);
}

void tftPrintTest() {
  tft.setTextWrap(false);
  tft.setCursor(50, 50);
  tft.setTextColor(ST77XX_RED);
  tft.fillScreen(ST77XX_WHITE);
  tft.setTextSize(3);
  tft.println("Hello World!");
}

void testlines(uint16_t color) {
  // X 
  delay(500);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(3);
  tft.print("Z=");
  tft.setTextColor(ST77XX_CYAN);
  tft.print(Z_out);
  // Y 
  tft.setCursor(0, 30);
  tft.setTextColor(color);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(3);
  tft.print("Y=");
  tft.setTextColor(ST77XX_CYAN);
  tft.print(Y_out);
  // Z
  tft.setCursor(0, 60);
  tft.setTextColor(color);
  tft.setTextColor(ST77XX_MAGENTA);
  tft.setTextSize(3);
  tft.print("X=");
  tft.setTextColor(ST77XX_CYAN);
  tft.print(X_out);

  //  delay(0);
  
  
}



