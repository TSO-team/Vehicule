#ifndef SERVICETENSIONLIMITEETS1508SCD_H
#define SERVICETENSIONLIMITEETS1508SCD_H

//MODULE: serviceTensionLimiteeTS1508SCD
//DESCRIPTION: pour faire en sorte que le canal CD du module interfaceTS1508S
//applique une tension
//moyenne qui varie lineairement suite a un passage d'une valeur de rapport cyclique
//non nulle a une autre et qu'il y ait desactivation immediate du module lorsque le
//rapport cyclique demande est nul.

//HISTORIQUE:
// 2020-11-15, Yves Roy, creation a partir de serviceTensionLimitee pour STM8

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define SERVICETENSIONLIMITEETS1508SCD_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
//#define SERVICETENSIONLIMITEETS1508SCD_DUREE_DES_PAS_EN_MS 200.0

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define SERVICETENSIONLIMITEETS1508SCD_PHASE 0

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void serviceTensionLimiteeTS1508SCD_initialise(void);

//Variables publiques:
extern signed char serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne;

#endif
