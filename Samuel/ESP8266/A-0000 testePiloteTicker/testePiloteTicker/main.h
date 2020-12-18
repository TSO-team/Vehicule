#ifndef MAIN_H
#define MAIN_H

//PROGRAMME: programme testePiloteTicker
//DESCRIPTION: programme qui permet de tester le module piloteTicker pour le ESP32
//Le programme associe la fonction "clignote" à l'objet "clignotant" lors de sa création.
//L'objet "clignotant" qui est de type Ticker appel la fonction "clignote" a chaque "periode_en_ms".
//La fonction "clignote" fait changer l'état de la DEL rouge du module Adafruit ESP32 a chaque "demi_periode_en_ms".

//HISTORIQUE:
// 2020-11-13, Yves Roy: creation

//inclusions globales
#include <arduino.h>

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles:
//pas de dependances materielles

//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
