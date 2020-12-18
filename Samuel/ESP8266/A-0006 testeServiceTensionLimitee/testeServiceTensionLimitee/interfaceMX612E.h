#ifndef INTERFACEMX612E_H
#define INTERFACEMX612E_H

//MODULE: interfaceMX612E
//DESCRIPTION: pour s'interfacer avec un circuit de commande de moteur c.c. MX612E. 
//Deux signaux PWM sont utilises pour alimenter les entrees INA et INB du circuit.
//La valeur de interfaceMX612E_rapportEnPourcentPourAB determine le rapport cyclique qui
//est applique a l'une ou l'autre des entrees INA et INB du MX612E. Une valeur positive
//fait en sorte qu'un signal PWM est applique a l'entree INA tandis que l'entree INB est a
//zero. Une valeur negative fait plutôt en sorte qu'un signal PWM est applique a l'entree
//INB tandis que l'entree INA est a zero. Une valeur nulle de rapport cyclique desactive
//les sorties OUTA et OUTB.
//OPTIONS:
//INTERFACEMX612E_OPTION_FREIN_ACTIF_POUR_AB: INA et INB sont mis a 0 
//lorsque le rapport cyclique demande est 0
//INTERFACEMX612E_OPTION_FREIN_INACTIF_POUR_AB: INA et INB sont mis a 1
//lorsque le rapport cyclique demande est 0

//HISTORIQUE:
// 2020-11-15, Yves Roy, creation a partir de interfaceMX612E

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEMX612E_OPTION_FREIN_ACTIF_POUR_AB
//#define INTERFACEMX612E_OPTION_FREIN_INACTIF_POUR_AB
//#define INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(rr) (\
//		pilotePWM_modifieLeRapportCyclique0(rr))
//#define INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(rr) (\
//		pilotePWM_modifieLeRapportCyclique5(rr))

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACEMX612E_PHASE 0

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//VALIDATIONS PUBLIQUES:
#ifdef INTERFACEMX612E_OPTION_FREIN_ACTIF_POUR_AB
	#ifdef INTERFACEMX612E_OPTION_FREIN_INACTIF_POUR_AB
		#error "InterfaceMX612E: plus d'une option de frein en meme temps"
	#endif
#endif

#ifndef INTERFACEMX612E_OPTION_FREIN_ACTIF_POUR_AB
  #ifndef INTERFACEMX612E_OPTION_FREIN_INACTIF_POUR_AB
    #error "InterfaceMX612E: il faut choisir une option de frein"
  #endif
#endif

//Fonctions publiques:
void interfaceMX612E_initialise(void);

//Variables publiques:
extern signed char interfaceMX612E_rapportEnPourcentageSigne;

#endif
