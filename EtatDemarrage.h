// EtatDemarrage.h

#ifndef _ETATDEMARRAGE_h
#define _ETATDEMARRAGE_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
#else
    #include "WProgram.h"
#endif


#include "Enum.h"
#include "IEtat.h"
#include "Vis.h"
#include "Bougie.h"
#include "Ventillo.h"
#include <Arduino.h>
#include "EtatMarche.h"

/*
    Definition de l'état Demarrage
*/
class EtatDemarrage : public IEtat
{
    const int DELAI_ALLIMENTATION_PELLET = 10000;
    const int DELAI_CHAUFFE_BOUGIE = 20000;

    IEtat* etatMarche;
public:
    EtatDemarrage(Relays* relays, IEtat* etatMarche)
    {
        this->relays = relays;
        this->etatMarche = etatMarche;
    }
    EtatEnum getEtat() { return DEMARRAGE; }
    void setup()
    {
    }
    IEtat* loop(unsigned long millis)
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
            // chauffe de la bougie, entre 10000ms et 30000ms
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
            // 
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
    void onEnter(unsigned long millis)
    {
        this->relays->vis->setRapport(1);
    }

};

#endif

