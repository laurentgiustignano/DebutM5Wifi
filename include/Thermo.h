
//
// Created by Laurent Giustignano on 10/05/2021.
//

#ifndef DEBUTM5WIFI_THERMO_H
#define DEBUTM5WIFI_THERMO_H



#include <M5Stack.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define TAILLEWIFI 3

class Thermo{
private:
    String ssid;
public:
    const String &getSsid() const;
private:
    String password;
    int selectionWifi;
    String listeWifi[TAILLEWIFI] = {"4G", "Lycee", "Maison"};

public:

    Thermo();
    Thermo(int);
    void choixWifi();
    void Wificonnect();

};

#define TO_CONNECT
#define DEBUG

// Identifiants Spot Wifi
// Ajoutez vos identifiants personnels
// pour votre connexion 4G et pour la maison

// Choix 4G
#define SSID4G ""
#define PASSWORD4G ""

// Choix Lycée
#define SSIDL "llw-iot"
#define PASSWORDL "iotllw94"

// Choix Maison
#define SSIDM "";
#define PASSWORDM "";

void retourAdresseIPv4(u_long,char *);

#endif //DEBUTM5WIFI_THERMO_H
