#ifndef PILOTESORTIEDEL2_H
#define PILOTESORTIEDEL2_H

//MODULE: piloteSortieDEL2
//DESCRIPTION: pour permettre la commande d'une DEL
// 2020-11-14, Yves Roy, creation a partir de piloteSortieDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PILOTESORTIEDEL2_BROCHE 4 
//#define PILOTESORTIEDEL2_ETAT_INITIAL_A_UN
//#define PILOTESORTIEDEL2_ETAT_INITIAL_A_ZERO

//Dependances logicielles
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
// pas de definitions publiques

//Fonctions publiques:
void piloteSortieDEL2_metAUn(void);
void piloteSortieDEL2_metAZero(void);
void piloteSortieDEL2_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
