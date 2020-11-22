#ifndef MAIN_H
#define MAIN_H

//PROGRAMME: programme testeInterfaceDEL
//DESCRIPTION: programme qui permet de tester le module interfaceDEL,
//interfaceDELAvantGauche, interfaceDELAvantDroite, interfaceDELArriereGauche
//et interfaceDELArriereDroite en faisant clignoter les DEL correpondantes 
//quand une entree est a zero et en les gardant allumees quand elle est a un
//HISTORIQUE:
//2020-11-14, Yves Roy: creation
//2020-11-15, Yves Roy: ajoute des interfaces avant, arriere, gauche et droite

//inclusions globales
#include <arduino.h>

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles:
#define PILOTEENTREELIMITEBASSE_BROCHE 34
#define PILOTESORTIEDEL_BROCHE 13
#define PILOTESORTIEDEL_ETAT_INITIAL_A_ZERO
#define PILOTESORTIEDEL1_BROCHE 27
#define PILOTESORTIEDEL1_ETAT_INITIAL_A_ZERO
#define PILOTESORTIEDEL2_BROCHE 4
#define PILOTESORTIEDEL2_ETAT_INITIAL_A_ZERO
#define PILOTESORTIEDEL3_BROCHE 21
#define PILOTESORTIEDEL3_ETAT_INITIAL_A_ZERO
#define PILOTESORTIEDEL4_BROCHE 26
#define PILOTESORTIEDEL4_ETAT_INITIAL_A_ZERO

#define INTERFACEDEL_ALLUME_LA_DEL() (piloteSortieDEL_metAUn())
#define INTERFACEDEL_ETEINT_LA_DEL() (piloteSortieDEL_metAZero())
#define INTERFACEDEL1_ALLUME_LA_DEL() (piloteSortieDEL1_metAUn())
#define INTERFACEDEL1_ETEINT_LA_DEL() (piloteSortieDEL1_metAZero())
#define INTERFACEDEL2_ALLUME_LA_DEL() (piloteSortieDEL2_metAUn())
#define INTERFACEDEL2_ETEINT_LA_DEL() (piloteSortieDEL2_metAZero())
#define INTERFACEDEL3_ALLUME_LA_DEL() (piloteSortieDEL3_metAUn())
#define INTERFACEDEL3_ETEINT_LA_DEL() (piloteSortieDEL3_metAZero())
#define INTERFACEDEL4_ALLUME_LA_DEL() (piloteSortieDEL4_metAUn())
#define INTERFACEDEL4_ETEINT_LA_DEL() (piloteSortieDEL4_metAZero())

//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1.0
#define INTERFACEDEL_TEMPS_ALLUME_EN_MS 500
#define INTERFACEDEL_TEMPS_ETEINT_EN_MS 500
#define INTERFACEDEL1_TEMPS_ALLUME_EN_MS 10
#define INTERFACEDEL1_TEMPS_ETEINT_EN_MS 90
#define INTERFACEDEL2_TEMPS_ALLUME_EN_MS 20
#define INTERFACEDEL2_TEMPS_ETEINT_EN_MS 80
#define INTERFACEDEL3_TEMPS_ALLUME_EN_MS 30
#define INTERFACEDEL3_TEMPS_ETEINT_EN_MS 70
#define INTERFACEDEL4_TEMPS_ALLUME_EN_MS 40
#define INTERFACEDEL4_TEMPS_ETEINT_EN_MS 60

#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 6
#define MAIN_TEST_PHASE 0
#define INTERFACEDEL_PHASE 1
#define INTERFACEDEL1_PHASE 2
#define INTERFACEDEL2_PHASE 3
#define INTERFACEDEL3_PHASE 4
#define INTERFACEDEL4_PHASE 5

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
