#ifndef INTERFACELIMITEBASSE_H
#define INTERFACELIMITEBASSE_H

//MODULE: interfaceLimiteBasse
//DESCRIPTION: pour s'interfacer avec un interrupteur de fin de course qui detecte
//la limite basse d'un deplacement
//L'etat de l'entree est lu periodiquement et les decisions rendues par rapport a
//son etat se basent sur un nombre minimum de lectures afin de reduire les risques
//d'erreurs causees par des rebondissements ou du bruit.
//La frequence INTERFACELIMITEBASSE_FREQUENCE_DES_LECTURES_EN_HZ des lectures 
//du bouton doit etre un multiple de la frequence de la base de temps utilisee.
//Le nombre minimum de lectures est donne par
//INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION

//HISTORIQUE:
// 2020-11-13, Yves Roy, creation à partir de interfaceLimiteBassePourSTM8

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_ACTIVE  0   
//#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_INACTIVE 1
//#define INTERFACELIMITEBASSE_FREQUENCE_DES_LECTURES_EN_HZ  100
//#define INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION 10

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACELIMITEBASSE_PHASE 0

//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INTERFACELIMITEBASSE_MODULE_EN_FONCTION 1
#define INTERFACELIMITEBASSE_MODULE_PAS_EN_FONCTION 0
#define INTERFACELIMITEBASSE_INFORMATION_DISPONIBLE 1
#define INTERFACELIMITEBASSE_INFORMATION_TRAITEE 0
#define INTERFACELIMITEBASSE_INACTIVE 0
#define INTERFACELIMITEBASSE_ACTIVE  1
#define INTERFACELIMITEBASSE_INCONNUE 2

typedef struct LIMITEBASSE
{
  unsigned char etatDuModule;  
  unsigned char information;
  unsigned char etatDeLEntree;
} INTERFACELIMITEBASSE;

//Fonctions publiques:
void interfaceLimiteBasse_initialise(void);

//Variables publiques:
extern INTERFACELIMITEBASSE interfaceLimiteBasse;

#endif
