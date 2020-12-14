#ifndef INTERFACEDEL1_H
#define INTERFACEDEL1_H

//MODULE: interfaceDEL1
//DESCRIPTION: pour s'interfacer avec une DEL 

//HISTORIQUE:
// 2020-11-15, Yves Roy, creation a partir de interfaceDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL1_ALLUME_LA_DEL() (piloteSortieDEL1_metAUn())
//#define INTERFACEDEL1_ETEINT_LA_DEL() (piloteSortieDEL1_metAZero())

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL1_PHASE 0
//#define INTERFACEDEL1_TEMPS_ALLUME_EN_MS 500
//#define INTERFACEDEL1_TEMPS_ETEINT_EN_MS 500

//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INTERFACEDEL1_ETEINT 0
#define INTERFACEDEL1_ALLUME 1
#define INTERFACEDEL1_CLIGNOTANT 2

//Fonctions publiques:
void interfaceDEL1_initialise(void);

//Variables publiques:
extern unsigned char interfaceDEL1_etatRequis;

#endif
