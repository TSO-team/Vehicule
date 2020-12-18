#ifndef MAIN_H
#define MAIN_H

//PROGRAMME: programme testeInterfaceMX612E
//DESCRIPTION: programme qui teste le fonctionnement du module interfaceMX612E en allumant une DEL
//et en faisant tourner une moteur lorsqu'un interrupteur de fin de course est active et qui garde la 
//DEL eteint et fait tourner le moteur dans le sens inverse quand l'interrupteur n'est pas active

//HISTORIQUE:
// 2020-11-15, Yves Roy: creation

//inclusions globales
#include <arduino.h>

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles:
#define PILOTEENTREELIMITEBASSE_BROCHE 34
#define PILOTESORTIEDEL_BROCHE 13
#define PILOTESORTIEDEL_ETAT_INITIAL_A_ZERO
#define PILOTEPWM_FREQUENCE_EN_KHZ 5000.0
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM0
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM1
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM2
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM3
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM4
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM5
#define PILOTEPWM_SORTIE0 25
#define PILOTEPWM_SORTIE1 32
#define PILOTEPWM_SORTIE2 14
#define PILOTEPWM_SORTIE3 33
#define PILOTEPWM_SORTIE4 15
#define PILOTEPWM_SORTIE5 5
#define INTERFACEMX612E_OPTION_FREIN_ACTIF_POUR_AB
#define INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(rr) (\
    pilotePWM_modifieLeRapportCyclique0(rr))
#define INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(rr) (\
    pilotePWM_modifieLeRapportCyclique5(rr))
#define INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_AB
#define INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_CD
#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(rr) (\
    pilotePWM_modifieLeRapportCyclique1(rr))
#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(rr) (\
    pilotePWM_modifieLeRapportCyclique2(rr))
#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_C(rr) (\
    pilotePWM_modifieLeRapportCyclique3(rr))
#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_D(rr) (\
    pilotePWM_modifieLeRapportCyclique4(rr))
#define SERVICETENSIONLIMITEETS1508SAB_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
#define SERVICETENSIONLIMITEETS1508SAB_DUREE_DES_PAS_EN_MS 200.0
#define SERVICETENSIONLIMITEETS1508SCD_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
#define SERVICETENSIONLIMITEETS1508SCD_DUREE_DES_PAS_EN_MS 200.0
#define SERVICETENSIONLIMITEEMX612E_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
#define SERVICETENSIONLIMITEEMX612E_DUREE_DES_PAS_EN_MS 200.0

//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1.0
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 6
#define MAIN_TEST_PHASE 0
#define SERVICETENSIONLIMITEETS1508SAB_PHASE 1
#define SERVICETENSIONLIMITEETS1508SCD_PHASE 2
#define SERVICETENSIONLIMITEEMX612E_PHASE 3
#define INTERFACEMX612E_PHASE 4
#define INTERFACETS1508S_PHASE 5

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
