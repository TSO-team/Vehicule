#ifndef PILOTEPWM_H
#define PILOTEPWM_H

//MODULE: pilotePWM
//DESCRIPTION: pour generer jusqu'à 5 signaux PWM
//Les signaux sont a 0 par defaut.
//La resolution est de 1/1024


//HISTORIQUE:
// 2020-11-13, Yves Roy, creation

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PILOTEPWM_FREQUENCE_EN_KHZ 5000.0
//#define PILOTEPWM_GENERE_LE_SIGNAL_PWM0
//#define PILOTEPWM_GENERE_LE_SIGNAL_PWM1
//#define PILOTEPWM_GENERE_LE_SIGNAL_PWM2
//#define PILOTEPWM_GENERE_LE_SIGNAL_PWM3
//#define PILOTEPWM_GENERE_LE_SIGNAL_PWM4
//#define PILOTEPWM_GENERE_LE_SIGNAL_PWM5

//#define PILOTEPWM_SORTIE0 25
//#define PILOTEPWM_SORTIE1 32
//#define PILOTEPWM_SORTIE2 14
//#define PILOTEPWM_SORTIE3 33
//#define PILOTEPWM_SORTIE4 15
//#define PILOTEPWM_SORTIE5 5

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
// pas de definitions publiques

//Fonctions publiques:
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM0
void pilotePWM_modifieLeRapportCyclique0(unsigned int RapportEnPourcent);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM1
void pilotePWM_modifieLeRapportCyclique1(unsigned int RapportEnPourcent);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM2
void pilotePWM_modifieLeRapportCyclique2(unsigned int RapportEnPourcent);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM3
void pilotePWM_modifieLeRapportCyclique3(unsigned int RapportEnPourcent);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM4
void pilotePWM_modifieLeRapportCyclique4(unsigned int RapportEnPourcent);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM5
void pilotePWM_modifieLeRapportCyclique5(unsigned int RapportEnPourcent);
#endif

void pilotePWM_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
