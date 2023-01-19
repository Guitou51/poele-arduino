#include "RapportCyclic.h"
#include "Relays.h"
#include "EtatArreter.h"
#include "EtatArret.h"
#include "Ventillo.h"
#include "Bougie.h"
#include "Vis.h"
#include "EtatMarche.h"
#include "EtatDemarrage.h"
#include "IEtat.h"
#include "Wire.h"
#include "Afficheur.h"
#include "EtatManager.h"
#include "pin.h"
#include "Enum.h"

DHT* dht = new DHT(DHT_INPUT, DHT11);
Afficheur* display = new Afficheur(dht);

Vis* vis = new Vis(VIS);
Bougie* bougie = new Bougie(BOUGIE);
Ventillo* ventillo = new Ventillo(VENTIL);
Relays* relays = new Relays(vis, bougie, ventillo);

EtatManager* etatManager = new EtatManager(relays, display);

void setup()
{
    Serial.begin(2000000);

    vis->setup();
    bougie->setup();
    ventillo->setup();

    pinMode(BOUTON, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(BOUTON), marcheArretClick, RISING);

    display->setup(millis());
}

void loop()
{
    auto ms = millis();
    etatManager->loop(ms);
}

void marcheArretClick()
{
    etatManager->marcheArretClick(millis());
}
