#ifndef INTERFACEDEL3_H
#define INTERFACEDEL3_H

//MODULE: interfaceDEL3
//DESCRIPTION: pour s'interfacer avec une DEL 

//HISTORIQUE:
// 2020-11-14, Yves Roy, creation a partir de interfaceDEL

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL3_ALLUME_LA_DEL() (piloteSortieDEL3_metAUn())
//#define INTERFACEDEL3_ETEINT_LA_DEL() (piloteSortieDEL3_metAZero())

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEDEL3_PHASE 0
//#define INTERFACEDEL3_TEMPS_ALLUME_EN_MS 500
//#define INTERFACEDEL3_TEMPS_ETEINT_EN_MS 500

//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INTERFACEDEL3_ETEINT 0
#define INTERFACEDEL3_ALLUME 1
#define INTERFACEDEL3_CLIGNOTANT 2

//Fonctions publiques:
void interfaceDEL3_initialise(void);

//Variables publiques:
extern unsigned char interfaceDEL3_etatRequis;

#endif
