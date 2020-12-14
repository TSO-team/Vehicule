#ifndef PROCESSUSCONDUITE_H
#define PROCESSUSCONDUITE_H
// DESCRIPTION: implemente la gestion du processus principal qui gère le 
//              transport dans le cadre du projet de fin de 5è session :
//              Usine de tri

// Copiez et adaptez ce qui suit dans "main.h"
// #define PROCESSUSCOMMUNICATION_PHASE 2

#define PROCESSUSCONDUITE_MODE_ARRET		0
#define PROCESSUSCONDUITE_MODE_AVANCE		1
#define PROCESSUSCONDUITE_MODE_RECULE		2
#define PROCESSUSCONDUITE_MODE_DEMI_GAUCHE	3
#define PROCESSUSCONDUITE_MODE_DEMI_DROITE	4
#define PROCESSUSCONDUITE_MODE_VIRE_GAUCHE	5
#define PROCESSUSCONDUITE_MODE_VIRE_DROITE	6

#define PROCESSUSCONDUITE_DIRECTION_AVANT	10
#define PROCESSUSCONDUITE_DIRECTION_ARRIERE 11

void processusConduite_initialise(void);
#endif

