#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_FeatherOLED.h>
#include "MaGestionDeClientUDP.h"

const int pinBoutonA = 0;
const int pinBoutonB = 16;
const int pinBoutonC = 2;

Adafruit_FeatherOLED oled = Adafruit_FeatherOLED();
Adafruit_SSD1306 display = Adafruit_SSD1306();
unsigned char vieuxA = HIGH;
unsigned char vieuxB = HIGH;
unsigned char vieuxC = HIGH;
unsigned char vieuxTampon[4]={LOW, LOW, LOW, LOW};

void initialiseLaGestionDeClientUDP()
{
  pinMode(pinBoutonA, INPUT_PULLUP);
  pinMode(pinBoutonB, INPUT_PULLUP);
  pinMode(pinBoutonC, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("247-527!!!");
   display.setTextSize(1); 
  display.println("client et UDP");
  display.display();
  display.setTextSize(1);
  delay(1000);
  display.clearDisplay();
}


void afficheLesValeursDeBouton(unsigned char A, unsigned char B, unsigned char C)
{
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(vieuxA);
  display.println(vieuxB);
  display.println(vieuxC);

  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(A);
  display.println(B);
  display.println(C);
  display.display();
  vieuxA = A;
  vieuxB = B;
  vieuxC = C;
}

void afficheLeMessageRecu(unsigned char *Tampon, unsigned char Longueur)
{
unsigned char index;
  display.setTextColor(BLACK);
  display.setCursor(32, 24);
  for (index = 0; index < Longueur; index++)
  {
    display.print(vieuxTampon[index]);
  }
  display.setTextColor(WHITE);
  display.setCursor(32, 24);  
  for (index = 0; index < Longueur; index++)
  {
    display.print(Tampon[index]);
    vieuxTampon[index] = Tampon[index];
  }
  display.display();
}

int litLeBoutonA()
{
  return digitalRead(pinBoutonA);
}

int litLeBoutonB()
{
  return digitalRead(pinBoutonB);
}

int litLeBoutonC()
{
  return digitalRead(pinBoutonC);
}


