#ifndef PILOTESORTIEDEL3_H
#define PILOTESORTIEDEL3_H

//MODULE: piloteSortieDEL3
//DESCRIPTION: pour permettre la commande d'une DEL
// 2020-11-15, Yves Roy, creation a partir de piloteSortieDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PILOTESORTIEDEL3_BROCHE 21
//#define PILOTESORTIEDEL3_ETAT_INITIAL_A_UN
//#define PILOTESORTIEDEL3_ETAT_INITIAL_A_ZERO

//Dependances logicielles
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
// pas de definitions publiques

//Fonctions publiques:
void piloteSortieDEL3_metAUn(void);
void piloteSortieDEL3_metAZero(void);
void piloteSortieDEL3_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
