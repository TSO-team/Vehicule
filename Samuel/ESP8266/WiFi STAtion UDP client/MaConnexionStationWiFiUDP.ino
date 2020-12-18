#define DEBUG

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "MaConnexionStationWiFiUDP.h"

const char *ssid = "etudiant10";
const char *motDePasse = "12345678";
const int tempsMaximumSansConnexion = 1000;
const unsigned int portLocal = 8000;

const char messageDeTypeStandard = 0; //message par défaut: type=0 suivi de 3 données
const char messageDErreur = 1;        //message d'erreur: type=1 suivi de 3 lettres
const int longueurMaximumDesTransmissions = 128;
const int longueurMaximumDesReceptions = 128;
const int longueurStandardDesTransmissions= 8;
const int longueurStandardDesReceptions = 8;

long tempsDeLaDerniereConnexion;
IPAddress ipServer(192, 168, 4, 1); //valeur pour les ESP8266
WiFiUDP udp;
byte tamponDeTransmission[longueurMaximumDesTransmissions];
byte tamponDeReception[longueurMaximumDesReceptions];

void configureLeWiFiEnStationAvecUDP()
{
#ifdef DEBUG
  Serial.begin(115200);
#endif

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, motDePasse);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
#ifdef DEBUG
    Serial.print(".");
#endif
  }
  udp.begin(portLocal);  
#ifdef DEBUG
  Serial.printf("\n");
  Serial.println("WiFi et UDP ok!");
  
#endif
  
}

boolean detecteUnProblemeDeConnexion() {
  long tempsPresent = millis();
  if (tempsPresent - tempsDeLaDerniereConnexion > tempsMaximumSansConnexion) {
    return true;
  }
  else
  {
    return false;
  }
}

void transmetUnMessageUDP(int longueurDuMessage)
{
    udp.beginPacket(ipServer, portLocal); //ouvre avec adresse ip et port local
    udp.write(tamponDeTransmission, longueurDuMessage); //envoye les 8 premières valeurs de tamponDeTransmission
    udp.endPacket(); //termine la communication.
#ifdef DEBUG
    Serial.printf("Transmission:");
    for (int i=0; i < longueurDuMessage; i++)
    {
      Serial.printf("\t %03d,", tamponDeTransmission[i]);
    }
    Serial.printf("\n");
#endif
}

int recoitUnMessageUDP()
{
  // trouve d'abord le nombre d'octets reçus (0 si pas de message reçu)
  int nombreDOctetsRecus = udp.parsePacket();
  if (nombreDOctetsRecus > longueurMaximumDesReceptions)
  {
    return 0; //ignore les paquets trop longs
  }
  else
  {
    if (nombreDOctetsRecus)
   {
      udp.read(tamponDeReception, nombreDOctetsRecus);
#ifdef DEBUG
      Serial.printf("Reception:\t %03d,");
      for (int i=1; i < nombreDOctetsRecus; i++)
      {
        if (tamponDeReception[0] == messageDErreur)
        {
          Serial.printf("%c", tamponDeReception[i]);
        }
        else
        {
          Serial.printf("\t %03d,", tamponDeReception[i]);
        }
      }
      Serial.printf("\n");
#endif      
      udp.flush();
    }
    return nombreDOctetsRecus;      
  }
}
