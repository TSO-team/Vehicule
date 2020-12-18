#ifndef MAIN_H
#define MAIN_H

//PROGRAMME: programme testeInterfaceTS1508S
//DESCRIPTION: programme qui teste le fonctionnement du module interfaceTS1508S en allumant une DEL
//et en faisant tourner une moteur lorsqu'un interrupteur de fin de course est active et qui garde la 
//DEL eteint et fait tourner le moteur dans le sens inverse quand l'interrupteur n'est pas active

//HISTORIQUE:
// 2020-11-14, Yves Roy: creation

//inclusions globales
#include <arduino.h>

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles:
#define PILOTEENTREELIMITEBASSE_BROCHE 34
#define PILOTESORTIEDEL_BROCHE 13
#define PILOTESORTIEDEL_ETAT_INITIAL_A_ZERO
#define PILOTEPWM_FREQUENCE_EN_KHZ 5000.0
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM1
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM2
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM3
#define PILOTEPWM_GENERE_LE_SIGNAL_PWM4

//#define PILOTEPWM_SORTIE0 25
#define PILOTEPWM_SORTIE1 33
#define PILOTEPWM_SORTIE2 15              
#define PILOTEPWM_SORTIE3 32
#define PILOTEPWM_SORTIE4 14

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

//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1.0
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 2
#define MAIN_TEST_PHASE 0
#define INTERFACETS1508S_PHASE 1

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
