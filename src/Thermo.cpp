//
// Created by Laurent Giustignano on 10/05/2021.
//
#include "Thermo.h"

void Thermo::choixWifi() {
    short retour = 0;
    selectionWifi = 0;

    // Affichage Menu Wifi

    M5.Lcd.setTextColor(RED);
    M5.Lcd.setTextDatum(MC_DATUM);
    M5.Lcd.drawString("Ok", M5.Lcd.width() * 3 / 4, M5.Lcd.height() * 3 / 4 , 4);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextDatum(MR_DATUM);
    M5.Lcd.drawString("Choix du Wifi", M5.Lcd.width() / 2 , M5.Lcd.height() / 4, 4);
    M5.Lcd.drawString(listeWifi[selectionWifi], M5.Lcd.width() / 4, M5.Lcd.height() * 3 / 4 , 4);

    while (!retour) {
        M5.update();

        if(M5.BtnA.wasReleased()){
            selectionWifi = (selectionWifi + 1) % TAILLEWIFI;
            M5.Lcd.fillRect(0,150,150,50,BLACK);
            M5.Lcd.drawString(listeWifi[selectionWifi], M5.Lcd.width() / 4, M5.Lcd.height() * 3 / 4 , 4);
        }

        if ( M5.BtnC.wasReleased())
            retour = 1;
    }
    switch (selectionWifi) {
        case 0:
            ssid = SSID4G;
            password = PASSWORD4G;
            break;
        case 1:
            ssid = SSIDL;
            password = PASSWORDL;
            break;
        case 2:
            ssid = SSIDM;
            password = PASSWORDM;
            break;
    }

    M5.Lcd.clear(BLACK);
}

Thermo::Thermo() {
    ;
}

Thermo::Thermo(int choixWifi) : selectionWifi(choixWifi){
    ;
}

void Thermo::Wificonnect() {

    // Affichage Menu Connexion

    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.setTextSize(2);
    M5.Lcd.println("Connexions serveurs");
    M5.Lcd.println("-------------------");
    M5.Lcd.println("");
    M5.Lcd.print("-> Connect ");
    M5.Lcd.println(ssid);
    M5.Lcd.println("Connecting...");

    WiFi.disconnect(true);
    WiFi.begin(ssid.c_str(), password.c_str());


    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    M5.Lcd.println("WiFi connected");
    M5.Lcd.println("IP address: ");
    M5.Lcd.println(WiFi.localIP());
    M5.Lcd.println("");
}

const String &Thermo::getSsid() const {
    return ssid;
}


void retourAdresseIPv4(u_long lll, char * adresseIP){
    u_char aaa,bbb,ccc,ddd;
    aaa = (lll&0x000000FF);
    bbb = (lll&0x0000FF00)/0x00000100;
    ccc = (lll&0x00FF0000)/0x00010000;
    ddd = (lll&0xFF000000)/0x01000000;
    sprintf(adresseIP,"%d.%d.%d.%d",aaa,bbb,ccc,ddd);

}


