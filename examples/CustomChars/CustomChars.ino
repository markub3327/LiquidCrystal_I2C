//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

uint8_t bellChar[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
uint8_t noteChar[8]  = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};
uint8_t clockChar[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
uint8_t heartChar[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
uint8_t duckChar[8]  = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
uint8_t checkChar[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
uint8_t crossChar[8] = {0x0,0x1b,0xe,0x4,0xe,0x1b,0x0};
uint8_t retarrowChar[8] = {	0x1,0x1,0x5,0x9,0x1f,0x8,0x4};
  
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  lcd.createChar(0, bellChar);
  lcd.createChar(1, noteChar);
  lcd.createChar(2, clockChar);
  lcd.createChar(3, heartChar);
  lcd.createChar(4, duckChar);
  lcd.createChar(5, checkChar);
  lcd.createChar(6, crossChar);
  lcd.createChar(7, retarrowChar);
  lcd.home();
  
  lcd.print("Hello world...");
  lcd.setCursor(0, 1);
  lcd.print(" i ");
  lcd.printByte(3);
  lcd.print(" arduinos!");
  delay(5000);
  displayKeyCodes();
  
}

// display all keycodes
void displayKeyCodes(void) {
  uint8_t i = 0;
  while (1) {
    lcd.clear();
    lcd.print("Codes 0x"); lcd.print(i, HEX);
    lcd.print("-0x"); lcd.print(i+15, HEX);
    lcd.setCursor(0, 1);
    for (int j=0; j<16; j++) {
      lcd.printByte(i+j);
    }
    i+=16;
    
    delay(4000);
  }
}

void loop()
{

}

