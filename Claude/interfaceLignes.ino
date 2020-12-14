#include "EasyPCF8574.h"
#include "interfaceLignes.h"


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
(byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')


#define ESP32_SDA 23
#define ESP32_SCL 22


EasyPCF8574 pcf_A(0x3A, 0xFF); //PCF address, initial value PCF8275A = 3A, PCF8275 = 22




unsigned char interfaceLignes_litPCF(void)
{
    printf("\n" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(255 - pcf_A.getPCFValue(0x3A)));

    printf("\n%3X", (255 - pcf_A.getPCFValue(0x3A)));

    return (255 - pcf_A.getPCFValue(0x3A));
}

void interfaceLignes_initialise(void)
{
    //ESP32 example. You can use overloaded function with no parameters in startI2C() method.
    if (!pcf_A.startI2C(ESP32_SDA, ESP32_SCL)) {
        Serial.println("Not started. Check pin and address.");
        while (true);
    }
    //serviceBaseDeTemps_execute[INTERFACELIGNES_PHASE] = interfaceLignes_litPCF;
}
   


