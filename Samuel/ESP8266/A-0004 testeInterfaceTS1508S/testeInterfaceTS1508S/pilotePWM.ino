//pilotePWM:
//Historique: 
// 2020-11-14, Yves Roy, creation

//Note: https://randomnerdtutorials.com/esp32-pwm-arduino-ide/ donne de l'information a propos des pwm du esp32

//INCLUSIONS
#include "main.h"
#include "pilotePWM.h"

//Definitions privees
#define PILOTEPWM_RESOLUTION 10
#define PILOTEPWM_COMPTE_SEUIL 1023 //2^PILOTEPWM_RESOLUTION - 1 (0 = 0%, 1023 = 100%)
    
//Declarations de fonctions privees:
//pas de fonctions privees

//Definitions de variables privees:
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM0
unsigned int pilotePWM_rapportEnCompte0;
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM1
unsigned int pilotePWM_rapportEnCompte1;
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM2
unsigned int pilotePWM_rapportEnCompte2;
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM3
unsigned int pilotePWM_rapportEnCompte3;
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM4
unsigned int pilotePWM_rapportEnCompte4;
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM5
unsigned int pilotePWM_rapportEnCompte5;
#endif

//Definitions de fonctions privees:
//pas de foncions privees

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM0
void pilotePWM_modifieLeRapportCyclique0(unsigned int RapportEnPourcent)
{
	unsigned long compte;
	compte = (unsigned long)RapportEnPourcent;
	compte *= (unsigned long)PILOTEPWM_COMPTE_SEUIL;
	compte /= 100;
  ledcWrite(0, (unsigned int)compte);
}
#endif

#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM1
void pilotePWM_modifieLeRapportCyclique1(unsigned int RapportEnPourcent)
{
  unsigned long compte;
  compte = (unsigned long)RapportEnPourcent;
  compte *= (unsigned long)PILOTEPWM_COMPTE_SEUIL;
  compte /= 100;
  ledcWrite(1, (unsigned int)compte);
}
#endif

#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM2
void pilotePWM_modifieLeRapportCyclique2(unsigned int RapportEnPourcent)
{
  unsigned long compte;
  compte = (unsigned long)RapportEnPourcent;
  compte *= (unsigned long)PILOTEPWM_COMPTE_SEUIL;
  compte /= 100;
  ledcWrite(2, (unsigned int)compte);
}
#endif

#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM3
void pilotePWM_modifieLeRapportCyclique3(unsigned int RapportEnPourcent)
{
  unsigned long compte;
  compte = (unsigned long)RapportEnPourcent;
  compte *= (unsigned long)PILOTEPWM_COMPTE_SEUIL;
  compte /= 100;
  ledcWrite(3, (unsigned int)compte);
}
#endif

#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM4
void pilotePWM_modifieLeRapportCyclique4(unsigned int RapportEnPourcent)
{
  unsigned long compte;
  compte = (unsigned long)RapportEnPourcent;
  compte *= (unsigned long)PILOTEPWM_COMPTE_SEUIL;
  compte /= 100;
  ledcWrite(4, (unsigned int)compte);
}
#endif

#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM5
void pilotePWM_modifieLeRapportCyclique5(unsigned int RapportEnPourcent)
{
  unsigned long compte;
  compte = (unsigned long)RapportEnPourcent;
  compte *= (unsigned long)PILOTEPWM_COMPTE_SEUIL;
  compte /= 100;
  ledcWrite(5, (unsigned int)compte);
}
#endif

void pilotePWM_initialise(void)
{
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM0
  ledcSetup(0, PILOTEPWM_FREQUENCE_EN_KHZ, PILOTEPWM_RESOLUTION);
  ledcAttachPin(PILOTEPWM_SORTIE0, 0);
  ledcWrite(0, 0);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM1
  ledcSetup(1, PILOTEPWM_FREQUENCE_EN_KHZ, PILOTEPWM_RESOLUTION);
  ledcAttachPin(PILOTEPWM_SORTIE1, 1);
  ledcWrite(1, 0);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM2
  ledcSetup(2, PILOTEPWM_FREQUENCE_EN_KHZ, PILOTEPWM_RESOLUTION);
  ledcAttachPin(PILOTEPWM_SORTIE2, 2);
  ledcWrite(2, 0);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM3
  ledcSetup(3, PILOTEPWM_FREQUENCE_EN_KHZ, PILOTEPWM_RESOLUTION);
  ledcAttachPin(PILOTEPWM_SORTIE3, 3);
  ledcWrite(3, 0);
#endif
#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM4
  ledcSetup(4, PILOTEPWM_FREQUENCE_EN_KHZ, PILOTEPWM_RESOLUTION);
  ledcAttachPin(PILOTEPWM_SORTIE4, 4);
  ledcWrite(4, 0);
#endif

#ifdef PILOTEPWM_GENERE_LE_SIGNAL_PWM5
  ledcSetup(5, PILOTEPWM_FREQUENCE_EN_KHZ, PILOTEPWM_RESOLUTION);
  ledcAttachPin(PILOTEPWM_SORTIE5, 5);
  ledcWrite(5, 0);
#endif
}
