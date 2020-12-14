#ifndef PILOTESORTIEDEL1_H
#define PILOTESORTIEDEL1_H

//MODULE: piloteSortieDEL1
//DESCRIPTION: pour permettre la commande du feu avant gauche du véhicule
// 2020-11-15, Yves Roy, creation a partir de piloteSortieDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PILOTESORTIEDEL1_BROCHE 27
//#define PILOTESORTIEDEL1_ETAT_INITIAL_A_UN
//#define PILOTESORTIEDEL1_ETAT_INITIAL_A_ZERO

//Dependances logicielles
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
// pas de definitions publiques

//Fonctions publiques:
void piloteSortieDEL1_metAUn(void);
void piloteSortieDEL1_metAZero(void);
void piloteSortieDEL1_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
