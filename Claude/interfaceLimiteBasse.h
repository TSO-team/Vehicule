#ifndef INTERFACELIMITEBASSE_H
#define INTERFACELIMITEBASSE_H

//MODULE: interfaceLimiteBasse
//DESCRIPTION: pour s'interfacer avec le bouton B1. 
//L'etat du bouton est lu periodiquement et les decisions rendues par rapport a
//son etat se base sur un nombre minimum de lecture afin de reduire les risques
//d'erreurs causees par des rebondissements ou du bruit.
//La fréquence interfaceLimiteBasse_FREQUENCE_DES_LECTURES_EN_HZ des lectures 
//du bouton doit être un multiple de la fréquence de la base de temps utilisée.
//Le nombre minimum de lecture est donne par
//interfaceLimiteBasse_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION

//HISTORIQUE:
// 2018-09-08, Yves Roy, creation

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_APPUYE  1   
//#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_RELACHE 0
//#define INTERFACELIMITEBASSE_FREQUENCE_DES_LECTURES_EN_HZ  100
//#define INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION 10

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACELIMITEBASSE_PHASE 0

//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INTERFACELIMITEBASSE_RELACHE  0
#define INTERFACELIMITEBASSE_APPUYE  1
#define INTERFACELIMITEBASSE_INCONNU 2

typedef struct
{
	unsigned char etatDuModule;
	unsigned char information;
	unsigned char etatDuBouton;
} INTERFACELIMITEBASSE;

//Fonctions publiques:
void interfaceLimiteBasse_initialise(void);

//Variables publiques:
extern INTERFACELIMITEBASSE interfaceLimiteBasse;

#endif
