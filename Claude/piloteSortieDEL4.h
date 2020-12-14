#ifndef PILOTESORTIEDEL4_H
#define PILOTESORTIEDEL4_H

//MODULE: piloteSortieDEL4
//DESCRIPTION: pour permettre la commande d'une DEL
// 2020-11-15, Yves Roy, creation a partir de piloteSortieDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PILOTESORTIEDEL4_BROCHE 26
//#define PILOTESORTIEDEL4_ETAT_INITIAL_A_UN
//#define PILOTESORTIEDEL4_ETAT_INITIAL_A_ZERO

//Dependances logicielles
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
// pas de definitions publiques

//Fonctions publiques:
void piloteSortieDEL4_metAUn(void);
void piloteSortieDEL4_metAZero(void);
void piloteSortieDEL4_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
