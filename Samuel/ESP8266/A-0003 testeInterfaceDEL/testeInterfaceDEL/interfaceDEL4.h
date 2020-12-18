#ifndef INTERFACEDEL4_H
#define INTERFACEDEL4_H

//MODULE: interfaceDEL4
//DESCRIPTION: pour s'interfacer avec une DEL 

//HISTORIQUE:
// 2020-11-14, Yves Roy, creation a partir de interfaceDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL4_ALLUME_LA_DEL() (piloteSortieDEL4_metAUn())
//#define INTERFACEDEL4_ETEINT_LA_DEL() (piloteSortieDEL4_metAZero())

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL4_PHASE 0
//#define INTERFACEDEL4_TEMPS_ALLUME_EN_MS 500
//#define INTERFACEDEL4_TEMPS_ETEINT_EN_MS 500

//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INTERFACEDEL4_ETEINT 0
#define INTERFACEDEL4_ALLUME 1
#define INTERFACEDEL4_CLIGNOTANT 2

//Fonctions publiques:
void interfaceDEL4_initialise(void);

//Variables publiques:
extern unsigned char interfaceDEL4_etatRequis;

#endif
