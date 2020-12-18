#include <Ticker.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "MaConnexionStationWiFiUDP.h"
#include "MaGestionDeClientUDP.h"

Ticker monClientUDP;

void gereLeClientUDPISR()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    if (!udp)
    {
      udp.begin(portLocal);
    }
    //préparation du message udp
    tamponDeTransmission[0] = messageDeTypeStandard;
    tamponDeTransmission[1] = litLeBoutonA();
    tamponDeTransmission[2] = litLeBoutonB();
    tamponDeTransmission[3] = litLeBoutonC();
    
    transmetUnMessageUDP(longueurStandardDesTransmissions);
    recoitUnMessageUDP();
    
    //prend l'heure de la dernière connexion pour pouvoir détecter les déconnexions si ça arrive.
    tempsDeLaDerniereConnexion = millis();
  }
  else
  {
    if (detecteUnProblemeDeConnexion)
    {
      setup(); //on reprend tout si on perd la connexion      
    }
  }
}
 
void setup() {  
  initialiseLaGestionDeClientUDP();
  configureLeWiFiEnStationAvecUDP();

  //fonction qui dit à quel rythme il faut appelé une fonction et quelle fonction appelée.
  monClientUDP.attach(0.2, gereLeClientUDPISR); // la "fonction" gereLaManetteISR va être apppelé automatiquement à toutes les 0.1seconde.
}

void loop()
{ 
  afficheLesValeursDeBouton(tamponDeTransmission[1], tamponDeTransmission[2], tamponDeTransmission[3]);
  afficheLeMessageRecu(tamponDeReception, 4);  
}



