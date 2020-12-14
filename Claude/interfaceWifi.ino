/**************************************************************************************************
  Nom du fichier : Camion.ino
   Auteur : Stéphane Deschênes
   Date de création : 27 novembre 2020
  Version 0.1
  Programme pour tester le softAP

  si recoit "Je m'appelle tour", répond "Je m'appelle camion"

***************************************************************************************************/

// *************************************************************************************************
//  INCLUDES
// **************************************************************************************************
#include <WiFi.h>
#include <mDNS.h>
#include <WiFiUdp.h>

#include "interfaceMX612E.h"
#include "interfaceDEL1.h"
#include "interfaceDEL2.h"
#include "interfaceDEL3.h"
#include "interfaceDEL4.h"
#include "serviceBaseDeTemps.h"

// *************************************************************************************************
//  CONSTANTES
// *************************************************************************************************
/* VIDE */

// *************************************************************************************************
//  DECLARATION DE FONCTIONS
// *************************************************************************************************
void vSendBackAscii(char* buf, char cLength);
bool bDoReception(char* Buf);

void interfaceWifi_gereLaBenne(void);



// *************************************************************************************************
//  STRUCTURES ET UNIONS
// *************************************************************************************************
/* VIDE */

// *************************************************************************************************
// VARIABLES LOCALES
// *************************************************************************************************
char cSsid[] = "etudiant8";             //  your network SSID (name)
char cPassword[] = "etudiant8";       // your network password
unsigned int uiPort = 10024;      // local port to listen for UDP packets
WiFiUDP MonUdp;

unsigned int interfacewifi_variable = 0;
unsigned char interfaceWifi_gereVehicule = REPART;

char cReceivedBuffer[20];
uint8_t cTransmitBuffer1[] = "Je m'appelle camion";
uint8_t cTransmitBuffer2[] = "Je m'appelle touuuu";
uint8_t cTransmitBuffer3[] = "Je m'appelle tchuii";
char cSupposedReceivedBuffer1[] = "Je m'appelle tour";
char cSupposedReceivedBuffer2[] = "Je m'appelle pour";
char cSupposedReceivedBuffer3[] = "Je m'appelle puii";

unsigned char interfaceWifi_commandeBenne = INACTIVE;
unsigned long interfaceWifi_compteurTemoinBenne = 0;
signed int interfaceWifi_valeurPMW = 0;
unsigned char interfaceWifi_dejaBaisse = 'N';



// *************************************************************************************************
void interfaceWifi_initialise(void)
//
//  Auteur: Stéphane Deschênes
//  Date de création :  xx-xx-xx  - Date non utilisé pour le main
//  Version x.x  - Version non utilisé pour le main
//
//  Description: Initialisation
//  Paramètres d'entrées : Aucun
//  Paramètres de sortie : Aucun
//  Notes                : Aucune
//
// *************************************************************************************************
{
    // Open serial port
    Serial.begin(115200);


    WiFi.mode(WIFI_AP);
    WiFi.softAP(cSsid, cPassword);

    Serial.print("Access Point \"");
    Serial.print(cSsid);
    Serial.println("\" started");

    Serial.print("IP address:\t");
    Serial.println(WiFi.softAPIP());

    // Start the UDP connection
    MonUdp.begin(uiPort);

    Serial.println("Moi, c'est Camion, j'attend que tour me parle, ensuite,");
    Serial.println("je vais connaitre son adresse IP, avec MonUdp.remoteIP() ");
    Serial.println("");
    Serial.println("");

    
    serviceBaseDeTemps_execute[INTERFCAEWIFI_PHASE] = interfaceWifi_gere;
}

// *************************************************************************************************
void interfaceWifi_gere(void)
//
//  Auteur: Stéphane Deschênes
//  Date de création :  xx-xx-xx  - Date non utilisé pour le main
//  Version x.x  - Version non utilisé pour le main
//
//  Description: Programme principal
//  Paramètres d'entrées : Aucun
//  Paramètres de sortie : Aucun
//  Notes          : Aucune
//
// *************************************************************************************************
{
    //Serial.print("WOOO  ");
    
    interfaceWifi_gereLaBenne();

    if (bDoReception(cReceivedBuffer) == true)
    {
        //Serial.print("WOOO  ");

        if (memcmp(cReceivedBuffer, cSupposedReceivedBuffer1, sizeof(cSupposedReceivedBuffer1)) == 0)
        {
            Serial.print("Recu:  ");
            Serial.println(cReceivedBuffer);

            interfaceWifi_gereVehicule = ARRET;

            vSendBackAscii(cTransmitBuffer1, sizeof(cTransmitBuffer1));
        }

        if (memcmp(cReceivedBuffer, cSupposedReceivedBuffer2, sizeof(cSupposedReceivedBuffer2)) == 0)
        {
            Serial.print("Recu:  ");
            Serial.println(cReceivedBuffer);

            interfaceWifi_gereVehicule = REPART;

            vSendBackAscii(cTransmitBuffer2, sizeof(cTransmitBuffer2));
        }

        if (memcmp(cReceivedBuffer, cSupposedReceivedBuffer3, sizeof(cSupposedReceivedBuffer3)) == 0)
        {
            Serial.print("Recu:  ");
            Serial.println(cReceivedBuffer);

            interfaceWifi_commandeBenne = ACTIVE;

            vSendBackAscii(cTransmitBuffer3, sizeof(cTransmitBuffer3));
        }
    }
}


void interfaceWifi_gereLaBenne(void)
{
    interfaceMX612E_rapportEnPourcentageSigne = interfaceWifi_valeurPMW;

    if (interfaceWifi_commandeBenne == ACTIVE)
    {
        interfaceWifi_dejaBaisse = 'Y';
    }
    else if (interfaceWifi_commandeBenne == INACTIVE)
    {
        interfaceWifi_dejaBaisse = 'N';
    }

    if (interfaceWifi_dejaBaisse == 'Y')
    {
        interfaceWifi_compteurTemoinBenne++;
        if (piloteEntreeLimiteBasse_lit() == 0)
        {

        }
        interfaceWifi_valeurPMW = -100;
        if (interfaceWifi_compteurTemoinBenne > 1200)
        {
            interfaceWifi_dejaBaisse = 'N';
            Serial.write('Y');
            interfaceWifi_commandeBenne = INACTIVE;
            interfaceWifi_compteurTemoinBenne = 0;
            interfaceWifi_valeurPMW = 0;
            interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
        }
    }


    if (interfaceWifi_dejaBaisse == 'N')
    {
        interfaceWifi_valeurPMW = 0;
    }
}

bool bDoReception(char* Buf)
{
    bool bReturnValue = false;
    if (MonUdp.parsePacket())
    {

        bReturnValue = true;
        MonUdp.read(Buf, 18);

    }
    return bReturnValue;
}



void vSendBackAscii(uint8_t* buf, char cLength)
{
    MonUdp.beginPacket(MonUdp.remoteIP(), uiPort);
    MonUdp.write(buf, cLength);
    MonUdp.endPacket();
}
