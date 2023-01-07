#include "EtatDemarrage.h"
#include <Arduino.h>

EtatDemarrage::EtatDemarrage(Relays* relays, IEtat* etatMarche)
{
    this->relays = relays;
    this->etatMarche = etatMarche;
}

void EtatDemarrage::onEnter(unsigned long millis)
{
    this->relays->vis->setRapport(1);
}

void EtatDemarrage::setup()
{
}

IEtat* EtatDemarrage::loop(unsigned long millis)
{
    unsigned long delta = millis - enterMillis;

    if (delta < DELAI_ALLIMENTATION_PELLET)
    {
        // alimentation des granulés entre 0 et 10000ms
        this->relays->bougie->off();
        this->relays->vis->on();
        this->relays->ventillo->off();
    }
    else if (delta > DELAI_ALLIMENTATION_PELLET && delta < DELAI_ALLIMENTATION_PELLET + DELAI_CHAUFFE_BOUGIE) 
    {
        // chauffe de la bougie, entre 10000ms et 20000ms
        this->relays->bougie->on();
    }
    else if (delta > DELAI_ALLIMENTATION_PELLET + DELAI_CHAUFFE_BOUGIE)
    {
        // fin du cicle de démarrage après 20000ms. 
        // on considere que le poele est allumé, qu'il n'y a pas eu de probleme d'allumage.
        // a faire: - ajouter une sonde de température de sortie de fumée pour mesurer s'il y a une flame
        //          - lire la sonde, si la température est supérieur a X degrés, on return etatMarche

        // if(temp > 100°C))
        // {
        //     this->relays->bougie->off();
        //     this->relays->ventillo->on();
        //     return etatMarche;
        // }

        this->relays->bougie->off();
        this->relays->ventillo->on();

        return etatMarche;
    }


    // if(temp > 80°){
    // this->relays->ventillo->on();
    // }

    return NULL;
}
