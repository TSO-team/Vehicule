#ifndef PILOTESORTIEDEL_H
#define PILOTESORTIEDEL_H

//MODULE: piloteSortieDEL
//DESCRIPTION: pour permettre la commande d'une DEL
// 2020-11-14, Yves Roy, creation a partir de piloteSortieDEL pour STM8

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PILOTESORTIEDEL_BROCHE 13
//#define PILOTESORTIEDEL_ETAT_INITIAL_A_UN
//#define PILOTESORTIEDEL_ETAT_INITIAL_A_ZERO

//Dependances logicielles
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
// pas de definitions publiques

//Fonctions publiques:
void piloteSortieDEL_metAUn(void);
void piloteSortieDEL_metAZero(void);
void piloteSortieDEL_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
