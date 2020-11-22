#ifndef MAIN_H
#define MAIN_H

//PROGRAMME: programme testeServiceBaseDeTemps
//DESCRIPTION:Programme qui teste le fonctionnement du module serviceBaseDeTemps en faisant clignoter une DEL
//HISTORIQUE:
// 2020-11-13, Yves Roy: creation

//inclusions globales
#include <arduino.h>

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles:
//pas de dependances materielles

//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1.0
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 1
#define MAIN_TEST_PHASE 0

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
