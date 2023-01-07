#ifndef ETAT
#define ETAT
#include <Arduino.h>
#include "Enum.h"

#include "IEtat.h"
#include "EtatDemarrage.h"
#include "EtatMarche.h"
#include "EtatArret.h"
#include "EtatArreter.h"
#include "Vis.h"
#include "Bougie.h"
#include "Ventillo.h"
#include "Afficheur.h"

/*
    Gestion de passage d'un état a un autre
*/
class EtatManager
{
private:
    IEtat* etatCourant;
    IEtat* etatDemarrage;
    IEtat* etatMarche;
    IEtat* etatArret;
    IEtat* etatArreter;
    Afficheur* display;
    Relays* relays;

    // affichage du changement d'état
    void printChangeEtat(IEtat* next, unsigned long ms);

    // éxecuter au changement d'état
    void changeEtat(IEtat* next, unsigned long ms);

public:
    EtatManager(Relays* relays, Afficheur* display);
    // action éxécuter a l'appui du bouton marche/arret
    void marcheArretClick(unsigned long ms);

    // éxecuter a chaque loop
    void loop(unsigned long ms);
};
#endif