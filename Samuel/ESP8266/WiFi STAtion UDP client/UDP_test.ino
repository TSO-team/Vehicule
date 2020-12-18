#include <WiFi.h>
#include <WiFiUdp.h>

#define LED 13
#define LED_ON (digitalWrite(LED, HIGH))
#define LED_OFF (digitalWrite(LED, LOW))
#define IP_ADRS "192.168.0.10"

WiFiUDP Udp;

const char* ssid = "HACKME";
const char* password = "HACKME123";

unsigned int localUdpPort = 1337;
int packetSize, wifi_status = WL_IDLE_STATUS;
unsigned char buffer[2];

void setup() {
    pinMode(LED, OUTPUT);
    LED_OFF;

    do {
        wifi_status = WiFi.begin(ssid, password);
        delay(500); 
    } while (wifi_status != WL_CONNECTED);

    Udp.begin(localUdpPort);
    LED_ON;
}


void loop() {
    packetSize = Udp.parsePacket();
    if (packetSize) {
        Udp.read(buffer, 2); 
        if ((buffer[2] & 0x20) == 0x20) digitalWrite(LED, !digitalRead(LED));  
    }

    Udp.beginPacket(IP_ADRS, localUdpPort);  
    Udp.write(0x20);
    Udp.write(0x00);
    Udp.endPacket();

    delay(1000);
}
