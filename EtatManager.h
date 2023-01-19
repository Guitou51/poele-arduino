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
    void printChangeEtat(IEtat* next, unsigned long ms)
    {
        Serial.print("Changement etat: ");
        Serial.print(next->getEtat());
        Serial.print(", ");
        Serial.print(ms);
        Serial.println("ms");
    }

    // éxecuter au changement d'état
    void changeEtat(IEtat* next, unsigned long ms)
    {
        printChangeEtat(next, ms);
        etatCourant->leave(ms);
        next->enter(ms);
        etatCourant = next;
    }

public:
    EtatManager(Relays* relays, Afficheur* display)
    {
        this->relays = relays;
        this->etatArreter = new EtatArreter(relays);
        this->etatArret = new  EtatArret(this->etatArreter, relays);
        this->etatMarche = new EtatMarche(this->etatArret, relays);
        this->etatDemarrage = new EtatDemarrage(relays, this->etatMarche);
        EtatArreter* a = (EtatArreter*)this->etatArreter;
        a->setEtatDemarrage(this->etatDemarrage);

        this->display = display;


        this->etatCourant = this->etatDemarrage;
        this->etatCourant->enter(0);
    }
    // action éxécuter a l'appui du bouton marche/arret
    void marcheArretClick(unsigned long ms)
    {
        IEtat* next = this->etatCourant->marcheArretClick(ms);
        if (next != NULL)
        {
            changeEtat(next, ms);

            if (next->getEtat() == DEMARRAGE)
            {
                this->display->setup(ms);
            }
        }
    }

    // éxecuter a chaque loop
    void loop(unsigned long ms)
    {
        auto next = etatCourant->loop(ms);
        this->relays->loop(ms);

        if (next != NULL)
        {
            changeEtat(next, ms);
        }
        this->display->loop(etatCourant->getEtat(), ms);
    }
};
#endif