#ifndef INTERFACETS1508S_H
#define INTERFACETS1508S_H

//MODULE: interfaceTS1508S
//DESCRIPTION: pour s'interfacer avec un circuit de commande de moteur c.c. TS1508S. 
//Deux signaux PWM sont utilises pour alimenter les entrees INA et INB du circuit.
//La valeur de interfaceTS1508S_rapportEnPourcentPourAB determine le rapport cyclique qui
//est applique a l'une ou l'autre des entrees INA et INB du TS1508S. Une valeur positive
//fait en sorte qu'un signal PWM est applique a l'entree INA tandis que l'entree INB est a
//zero. Une valeur negative fait plutôt en sorte qu'un signal PWM est applique a l'entree
//INB tandis que l'entree INA est a zero. Une valeur nulle de rapport cyclique desactive
//les sorties OUTA et OUTB.
//La valeur de interfaceTS1508S_rapportEnPourcentPourCD determine plutôt le rapport cyclique qui
//est applique a l'une ou l'autre des entrees INC et IND du TS1508S.
//OPTIONS:
//INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_AB: INA et INB sont mis a 0 
//lorsque le rapport cyclique demande est 0
//INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_AB: INA et INB sont mis a 1
//lorsque le rapport cyclique demande est 0
//INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_CD: INC et IND sont mis a 0 
//lorsque le rapport cyclique demande est 0
//INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_CD: INC et IND sont mis a 1
//lorsque le rapport cyclique demande est 0

//HISTORIQUE:
// 2020-11-14, Yves Roy, creation a partir de interfaceTS1508S

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_AB
//#define INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_AB
//#define INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_CD
//#define INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_CD
//#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(rr) (\
//		pilotePWM_modifieLeRapportCyclique1(rr))
//#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(rr) (\
//		pilotePWM_modifieLeRapportCyclique2(rr))
//#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_C(rr) (\
//    pilotePWM_modifieLeRapportCyclique3(rr))
//#define INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_D(rr) (\
//    pilotePWM_modifieLeRapportCyclique4(rr))

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACETS1508S_PHASE 0

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//VALIDATIONS PUBLIQUES:
#ifdef INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_AB
	#ifdef INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_AB
		#error "InterfaceTS1508S: plus d'une option de frein en meme temps"
	#endif
#endif
#ifdef INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_CD
  #ifdef INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_CD
    #error "InterfaceTS1508S: plus d'une option de frein en meme temps"
  #endif
#endif

#ifndef INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_AB
  #ifndef INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_AB
    #error "InterfaceTS1508S: il faut choisir une option de frein"
  #endif
#endif

#ifndef INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_CD
  #ifndef INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_CD
    #error "InterfaceTS1508S: il faut choisir une option de frein"
  #endif
#endif

//Fonctions publiques:
void interfaceTS1508S_initialise(void);

//Variables publiques:
extern signed char interfaceTS1508S_rapportEnPourcentageSignePourAB;
extern signed char interfaceTS1508S_rapportEnPourcentageSignePourCD;


#endif
