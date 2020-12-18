#ifndef PILOTEENTREELIMITEBASSE_H
#define PILOTEENTREELIMITEBASSE_H

//MODULE: piloteEntreeLimiteBasse
//DESCRIPTION: pour permettre la lecture d'une entree
// 2020-11-13, Yves Roy, creation a partir de piloteEntreeLimiteBasse pour STM8

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PILOTEENTREELIMITEBASSE_BROCHE 34

//Dependances logicielles
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
// pas de definitions publiques

//Fonctions publiques:
unsigned char piloteEntreeLimiteBasse_lit(void);
void piloteEntreeLimiteBasse_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
