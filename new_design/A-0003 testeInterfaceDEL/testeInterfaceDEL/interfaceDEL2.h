#ifndef INTERFACEDEL2_H
#define INTERFACEDEL2_H

//MODULE: interfaceDEL2
//DESCRIPTION: pour s'interfacer avec une DEL 

//HISTORIQUE:
// 2020-11-15, Yves Roy, creation a partir de interfaceDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL2_ALLUME_LA_DEL() (piloteSortieDEL2_metAUn())
//#define INTERFACEDEL2_ETEINT_LA_DEL() (piloteSortieDEL2_metAZero())

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL2_PHASE 0
//#define INTERFACEDEL2_TEMPS_ALLUME_EN_MS 500
//#define INTERFACEDEL2_TEMPS_ETEINT_EN_MS 500

//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INTERFACEDEL2_ETEINT 0
#define INTERFACEDEL2_ALLUME 1
#define INTERFACEDEL2_CLIGNOTANT 2

//Fonctions publiques:
void interfaceDEL2_initialise(void);

//Variables publiques:
extern unsigned char interfaceDEL2_etatRequis;

#endif
