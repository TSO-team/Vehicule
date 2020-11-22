//Programme: testePiloteTicker
//Historique:
// 2020-11-13, Yves Roy, creation

//Notes:
//Installation de la librairie Espressif pour le ESP32: https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md
//Nécessite Arduino IDE 1.8 ou plus
//Faire: Fichier -> Préferences
//Lien à ajouter: //https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
//Faire: Outils -> Type de carte -> Gestionnaire de carte et installer la librairie pour le ESP32
//Pour des exemples d'utilisation: Fichier -> Exemples -> Ticker -> Blinker ou Arguments
//DEL rouge pour le Adafruit ESP32 Huzzah: broche 13

//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"

//Definitions privees
#define MAIN_DEL 13
#define MAIN_DEMI_PERIODE_EN_MS 100
#define MAIN_ALLUME 1
#define MAIN_ETEINT 0

//Declarations de fonctions privees:
void main_teste(void);
void main_initialise(void);

//Definitions de variables privees:
unsigned int main_compteur;

//Definitions de fonctions privees:
void main_teste(void)
{
  main_compteur++;
  if (main_compteur < MAIN_DEMI_PERIODE_EN_MS)
  {
    return;
  }
  main_compteur = 0;
  digitalWrite(MAIN_DEL, !digitalRead(MAIN_DEL));
}

void main_initialise(void)
{
  piloteTicker_initialise();
}

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void neFaitRien(void)
{
}

void setup()
{
  main_initialise();
  main_compteur = 0;
  digitalWrite(MAIN_DEL, MAIN_ETEINT);
  pinMode(MAIN_DEL, OUTPUT);
  piloteTicker_execute = main_teste;
  piloteTicker_lanceLeTickerALaTouteFinDeSetup();
}

void loop()
{
  
}
