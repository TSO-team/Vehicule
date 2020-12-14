#ifndef MAIN_H
#define MAIN_H

//PROGRAMME: programme testeInterfaceLimiteBasse
//DESCRIPTION: Programme qui teste le fonctionnement du module interfaceLimiteBasse en allumant une DEL
//lorsque un interrupteur de fin de course est active et qui garde la DEL eteint quand l'interrupteur n'est
//pas active

//HISTORIQUE:
// 2020-11-13, Yves Roy: creation

//inclusions globales
#include <arduino.h>

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles:
#define PILOTEENTREELIMITEBASSE_BROCHE 34
#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_ACTIVE  0   
#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_INACTIVE 1
#define INTERFACELIMITEBASSE_FREQUENCE_DES_LECTURES_EN_HZ  100
#define INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION 10



//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1.0
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 2
#define MAIN_TEST_PHASE 0
#define INTERFACELIMITEBASSE_PHASE 1

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
