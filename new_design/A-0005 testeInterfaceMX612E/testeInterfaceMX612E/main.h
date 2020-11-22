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
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM5

#define PILOTEPWM_SORTIE0 25
#define PILOTEPWM_SORTIE5 5

#define INTERFACEMX612E_OPTION_FREIN_ACTIF_POUR_AB
#define INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(rr) (\
    pilotePWM_modifieLeRapportCyclique0(rr))
#define INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(rr) (\
    pilotePWM_modifieLeRapportCyclique5(rr))

//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1.0
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 2
#define MAIN_TEST_PHASE 0
#define INTERFACEMX612E_PHASE 1

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
