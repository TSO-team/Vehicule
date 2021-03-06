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
#define INTERFACEDEL_TEMPS_ALLUME_EN_MS 500
#define INTERFACEDEL_TEMPS_ETEINT_EN_MS 500

#define INTERFACEDEL1_ALLUME_LA_DEL() (piloteSortieDEL1_metAUn())
#define INTERFACEDEL1_ETEINT_LA_DEL() (piloteSortieDEL1_metAZero())
#define INTERFACEDEL1_TEMPS_ALLUME_EN_MS 500
#define INTERFACEDEL1_TEMPS_ETEINT_EN_MS 500

#define INTERFACEDEL2_ALLUME_LA_DEL() (piloteSortieDEL2_metAUn())
#define INTERFACEDEL2_ETEINT_LA_DEL() (piloteSortieDEL2_metAZero())
#define INTERFACEDEL2_TEMPS_ALLUME_EN_MS 500
#define INTERFACEDEL2_TEMPS_ETEINT_EN_MS 500

#define INTERFACEDEL3_ALLUME_LA_DEL() (piloteSortieDEL3_metAUn())
#define INTERFACEDEL3_ETEINT_LA_DEL() (piloteSortieDEL3_metAZero())
#define INTERFACEDEL3_TEMPS_ALLUME_EN_MS 500
#define INTERFACEDEL3_TEMPS_ETEINT_EN_MS 500

#define INTERFACEDEL4_ALLUME_LA_DEL() (piloteSortieDEL4_metAUn())
#define INTERFACEDEL4_ETEINT_LA_DEL() (piloteSortieDEL4_metAZero())
#define INTERFACEDEL4_TEMPS_ALLUME_EN_MS 500
#define INTERFACEDEL4_TEMPS_ETEINT_EN_MS 500

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

#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_APPUYE  1   
#define INTERFACELIMITEBASSE_VALEUR_LUE_SI_RELACHE 0
#define INTERFACELIMITEBASSE_FREQUENCE_DES_LECTURES_EN_HZ  100
#define INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION 10

#define SERVICETENSIONLIMITEETS1508SAB_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
#define SERVICETENSIONLIMITEETS1508SAB_DUREE_DES_PAS_EN_MS 200.0
#define SERVICETENSIONLIMITEETS1508SCD_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
#define SERVICETENSIONLIMITEETS1508SCD_DUREE_DES_PAS_EN_MS 200.0
#define SERVICETENSIONLIMITEEMX612E_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT 20
#define SERVICETENSIONLIMITEEMX612E_DUREE_DES_PAS_EN_MS 200.0

//Dependances logicielles:
#define PILOTETICKER_PERIODE_EN_MS 1.0

#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 18
#define MAIN_TEST_PHASE 0
#define SERVICETENSIONLIMITEETS1508SAB_PHASE 1
#define SERVICETENSIONLIMITEETS1508SCD_PHASE 2
#define SERVICETENSIONLIMITEEMX612E_PHASE 3
#define INTERFACEMX612E_PHASE 4
#define INTERFACETS1508S_PHASE 5
#define INTERFACEDEL_PHASE 6
#define INTERFACEDEL1_PHASE 7
#define INTERFACEDEL2_PHASE 8
#define INTERFACEDEL3_PHASE 9
#define INTERFACEDEL4_PHASE 10
#define INTERFCAEWIFI_PHASE 11
#define INTERFACELIMITEBASSE_PHASE 12
#define PROCESSUSBENNE_PHASE 13
#define PROCESSUSCONDUITE_PHASE 14
#define PROCESSUSCONDUITE_PHASE_DEPLACEMENT 15
#define PROCESSUSCONDUITE_PHASE_ACTION 16
#define INTERFACELIGNES_PHASE 17


//INFORMATION PUBLIQUE:
//Definitions publiques:
#define ACTIVE 1
#define INACTIVE 0

#define ARRET  0
#define REPART 1

#define INFORMATION_DISPONIBLE  1
#define INFORMATION_TRAITEE  0
#define REQUETE_ACTIVE  1
#define REQUETE_TRAITEE 0
#define MODULE_EN_FONCTION 1
#define MODULE_PAS_EN_FONCTION 0
#define MAIN_COMPTE_MAXIMUM 1000000
//pas de definitions publiques

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//pas de variables publiques
#endif
