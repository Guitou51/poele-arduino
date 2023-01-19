// EtatMarche.h

#ifndef _ETATMARCHE_h
#define _ETATMARCHE_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
#else
    #include "WProgram.h"
#endif

#include "Enum.h"
#include "IEtat.h"
#include <Arduino.h>
#include "EtatArret.h"

/*
    Definition de l'�tat Marche
*/
class EtatMarche : public IEtat
{
    IEtat* etatArret;
public:
    EtatMarche(IEtat* etatArret, Relays* relays)
    {
        this->etatArret = etatArret;
        this->relays = relays;
    }

    EtatEnum getEtat() { return MARCHE; }
    void setup()
    {
    }

    IEtat* loop(unsigned long millis)
    {
        // A faire: modifier le rapport de la vis en fonction de la temparature sortie fum�e et/ou temperature exterieur et/ou puissance demander et/ou ???
        // this->relays->vis->setRapport(valeurACalculer);

        // A faire: V�rification de la pr�sence de la flame. Si pas de flame, aller a l'�tat erreur
        // if(pasDeFlame){
        //     return etatErreur;
        // }


        return NULL;
    }

    IEtat* marcheArretClick(unsigned long ms)
    {
        Serial.println("EtatMarche::marcheArretClick()");
        return etatArret;
    }

    void onEnter(unsigned long millis)
    {
        this->relays->vis->setRapport(0.5);
        relays->vis->on();
        relays->ventillo->on();
    }

    void onLeave(unsigned long millis)
    {
        this->relays->vis->off();
    }
};

#endif

