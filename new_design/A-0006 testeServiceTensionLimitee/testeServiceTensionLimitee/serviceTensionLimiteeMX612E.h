#ifndef SERVICETENSIONLIMITEEMX612E_H
#define SERVICETENSIONLIMITEEMX612E_H

//MODULE: serviceTensionLimiteeMX612E
//DESCRIPTION: pour faire en sorte que le canal AB du module interfaceMX612E
//applique une tension
//moyenne qui varie lineairement suite a un passage d'une valeur de rapport cyclique
//non nulle a une autre et qu'il y ait desactivation immediate du module lorsque le
//rapport cyclique demande est nul.

//HISTORIQUE:
// 2020-11-15, Yves Roy, creation a partir de serviceTensionLimitee pour STM8

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define SERVICETENSIONLIMITEEMX612E_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
//#define SERVICETENSIONLIMITEEMX612E_DUREE_DES_PAS_EN_MS 200.0

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define SERVICETENSIONLIMITEEMX612E_PHASE 0

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void serviceTensionLimiteeMX612E_initialise(void);

//Variables publiques:
extern signed char serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne;

#endif
