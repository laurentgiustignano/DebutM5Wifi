#include "Thermo.h"

Thermo monThermo;

void setup() {

    delay(10);
    M5.begin(true, true, true);
    M5.Power.begin();
    M5.Lcd.clear(BLACK);
    monThermo.choixWifi();

#ifdef TO_CONNECT
    monThermo.Wificonnect();
#endif

    M5.Lcd.clear(BLACK);

#ifdef DEBUG
    Serial.begin(9600);
#endif
}

void loop() {

    char adresseIP[16] = "A.B.C.D";
    retourAdresseIPv4(WiFi.localIP(),adresseIP);

    M5.Lcd.setTextDatum(TL_DATUM);
    M5.Lcd.fillRect(0,80,60,60,BLACK);
    M5.Lcd.drawString("Connecte sur : " + monThermo.getSsid(),0,0);
    M5.Lcd.drawString("Adresse : " , 0, 20);
    M5.Lcd.drawString(adresseIP,0,40);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        M5.Lcd.clear(BLACK);
        M5.Lcd.drawString("Deconnecte du Wifi :" + monThermo.getSsid(),10,10);
    }

#ifdef DEBUG
        Serial.println("");
        Serial.print("Connected sur ");
        Serial.println(monThermo.getSsid());
        Serial.print("Adresse : ");
        Serial.println(WiFi.localIP());
#endif

    delayMicroseconds(2000000);
}