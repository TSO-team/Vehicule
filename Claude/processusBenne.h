#ifndef PROCESSUSBENNE_H
#define PROCESSUSBENNE_H

//MODULE: processusBenne
//DESCRIPTION: implemente la gestion des messages que s'echangent l'ensemble
//de developpement Dallas programme avec le logiciel 247-637 S-0002 (ou S-0005)
//et un ensemble STM32F4-DISCO (piste de solution du laboratoire 2)
//Un octet est transmis � chaque fois qu'on appuie sur le bouton B1 et
//l'ensemble Dallas retourne un octet a chaque fois qu'il en recoit un.
//Un temoin lumineux change d'etat a chaque fois qu'un octet est recu et un
//autre temoin lumineu s'allume ou s'eteint alors pour indiquer si le bouton
//de l'ensemble etait appuye ou relache au moment ou celui-ci a fait sa
//transmission.

//HISTORIQUE:
// 2018-09-30, Yves Roy, creation

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//pas de dependances materielles

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PROCESSUSBOUTONCONNECTE_TEMPS_MAXIMAL_POUR_RECEVOIR_EN_MS 100
//#define PROCESSUSBENNE_PHASE 0


//INFORMATION PUBLIQUE:
//Definitions publiques:
#define LEVEE	 'L'
#define BAISSEE	 'D'
#define ACTIVE   'Y'
#define INACTIVE 'N'
//pas de definitions publiques

//Fonctions publiques:
void processusBenne_initialise(void);

//Variables publiques:

unsigned char processusBenne_Requete;
unsigned int  processusBenne_ValeurPMW;
unsigned char processusBenne_commandeBenne;

//pas de variables publiques

#endif
