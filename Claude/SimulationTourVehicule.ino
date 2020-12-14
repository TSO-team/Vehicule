/**************************************************************************************************
  Nom du fichier : Tour.ino
   Auteur : Stéphane Deschênes
   Date de création : 3 décembre 2020
  Programme pour tester la librairie SoftAP


  Envoie "Je m'appelle tour" à tous les 500 ms
  devrait recevoir "Je m'appelle camion"


  
  
***************************************************************************************************/

// *************************************************************************************************
//  INCLUDES
// **************************************************************************************************
#include <WiFi.h>
#include <WiFiUdp.h>

// *************************************************************************************************
//  CONSTANTES
// *************************************************************************************************
/* VIDE */

// *************************************************************************************************
//  DECLARATION DE FONCTIONS
// *************************************************************************************************
void vSendAscii(uint8_t *buf,char cLength);
bool bDoReception(char *Buf);



// *************************************************************************************************
//  STRUCTURES ET UNIONS
// *************************************************************************************************
/* VIDE */

// *************************************************************************************************
// VARIABLES LOCALES
// *************************************************************************************************
char cSsid[]    = "etudiant8";         //  your network SSID (name)
char cPassword[]  = "etudiant8";       // your network password
unsigned int uiPort = 10024;          // local port to listen for UDP packets

unsigned long CurrentMillis;
unsigned long PreviousMillis = 0;

char cReceivedBuffer[20];
uint8_t cTransmitBuffer1[] = "Je m'appelle tour";
uint8_t cTransmitBuffer2[] = "Je m'appelle pour";
uint8_t cTransmitBuffer3[] = "Je m'appelle puii";
char cSupposedReceivedBuffer1[] = "Je m'appelle camion";
char cSupposedReceivedBuffer2[] = "Je m'appelle touuuu";
char cSupposedReceivedBuffer3[] = "Je m'appelle tchuii";

WiFiUDP MonUdp;


// *************************************************************************************************
void setup()
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

  WiFi.begin(cSsid, cPassword);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(250);
    Serial.print(".");
  }
  Serial.println("WiFi connected\n");
  Serial.println("Local IP address: ");
  Serial.println(WiFi.localIP());
  
  
    
  // Start the UDP connection
  MonUdp.begin(uiPort);
  Serial.println("\n");

  Serial.println("C'est moi, tour qui va commencer a parler en premier,"); 
  Serial.println("je connais l'adresse IP de camion");
  Serial.println("");
  Serial.println("");
}
  

// *************************************************************************************************
void loop()
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
  CurrentMillis = millis();

  //if (CurrentMillis - PreviousMillis >= 500)
  char receivedChar = Serial.read();

  
  if (receivedChar == 'U')
  {
    PreviousMillis = CurrentMillis;
    vSendAscii(cTransmitBuffer1,sizeof(cTransmitBuffer1));    
  }
  if (receivedChar == 'I')
  {
    PreviousMillis = CurrentMillis;
    vSendAscii(cTransmitBuffer2,sizeof(cTransmitBuffer2));    
  }
  if (receivedChar == 'O')
  {
    PreviousMillis = CurrentMillis;
    vSendAscii(cTransmitBuffer3,sizeof(cTransmitBuffer3));    
  }
  if (bDoReception(cReceivedBuffer) == true)
  {    
    if(memcmp(cReceivedBuffer,cSupposedReceivedBuffer3,sizeof(cSupposedReceivedBuffer3)) == 0)
    {
      Serial.print("Recu:  ");
      Serial.println(cReceivedBuffer);
    }
    if(memcmp(cReceivedBuffer,cSupposedReceivedBuffer2,sizeof(cSupposedReceivedBuffer2)) == 0)
    {
      Serial.print("Recu:  ");
      Serial.println(cReceivedBuffer);
    }
    if(memcmp(cReceivedBuffer,cSupposedReceivedBuffer1,sizeof(cSupposedReceivedBuffer1)) == 0)
    {
      Serial.print("Recu:  ");
      Serial.println(cReceivedBuffer);
    }
  }
}


bool bDoReception(char *Buf)
{
  bool bReturnValue = false;
  if (MonUdp.parsePacket())
  { 
    bReturnValue = true;
    MonUdp.read(Buf,20);
  }
  return bReturnValue;  
}



void vSendAscii(uint8_t *buf,char cLength)
{
  MonUdp.beginPacket("192.168.4.1", uiPort);
  MonUdp.write(buf, cLength);
  MonUdp.endPacket();
  
}
