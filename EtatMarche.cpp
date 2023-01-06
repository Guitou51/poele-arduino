// 
// 
// 

#include "EtatMarche.h"

EtatMarche::EtatMarche(IEtat* etatArret, Relays* relays)
{
    this->etatArret = etatArret;
    this->relays = relays;
}

void EtatMarche::setup()
{
}


IEtat* EtatMarche::loop(unsigned long millis)
{
    // A faire: modifier le rapport de la vis en fonction de la temparature sortie fumée et/ou temperature exterieur et/ou puissance demander et/ou ???
    // this->relays->vis->setRapport(valeurACalculer);

    // A faire: Vérification de la présence de la flame. Si pas de flame, aller a l'état erreur
    // if(pasDeFlame){
    //     return etatErreur;
    // }


    return NULL;
}

IEtat* EtatMarche::marcheArretClick(unsigned long ms)
{
    Serial.println("EtatMarche::marcheArretClick()");
    return etatArret;
}

void EtatMarche::onEnter(unsigned long millis)
{
    this->relays->vis->setRapport(0.5);
    relays->vis->on();
    relays->ventillo->on();
}

void EtatMarche::onLeave(unsigned long millis)
{
    this->relays->vis->off();
}
