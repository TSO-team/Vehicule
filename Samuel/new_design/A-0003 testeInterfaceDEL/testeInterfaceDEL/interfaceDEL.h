#ifndef INTERFACEDEL_H
#define INTERFACEDEL_H

//MODULE: interfaceDEL
//DESCRIPTION: pour s'interfacer avec une DEL 

//HISTORIQUE:
// 2020-11-14, Yves Roy, creation a partir de interfaceDEL pour STM8

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL_ALLUME_LA_DEL() (piloteSortieDEL_metAUn())
//#define INTERFACEDEL_ETEINT_LA_DEL() (piloteSortieDEL_metAZero())

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL_PHASE 0
//#define INTERFACEDEL_TEMPS_ALLUME_EN_MS 500
//#define INTERFACEDEL_TEMPS_ETEINT_EN_MS 500

//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INTERFACEDEL_ETEINT 0
#define INTERFACEDEL_ALLUME 1
#define INTERFACEDEL_CLIGNOTANT 2

//Fonctions publiques:
void interfaceDEL_initialise(void);

//Variables publiques:
extern unsigned char interfaceDEL_etatRequis;

#endif
