#ifndef MA_CONNEXION_STATION_WIFI_UDP
#define MA_CONNEXION_STATION_WIFI_UDP

extern const unsigned int portLocal;
extern const char messageDeTypeStandard;
extern const int longueurStandardDesTransmissions;
extern long tempsDeLaDerniereConnexion;
extern WiFiUDP udp;
extern byte tamponDeTransmission[];
extern byte tamponDeReception[];

void configureLeWiFiEnStationAvecUDP();
boolean detecteUnProblemeDeConnexion();
void transmetUnMessageUDP(int longueurDuMessage);
int recoitUnMessageUDP();

#endif

