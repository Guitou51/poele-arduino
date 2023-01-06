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
    const int DELAI_CHAUFFE_BOUGIE = 10000;

    IEtat* etatMarche;
public:
    EtatDemarrage(Relays* relays, IEtat* etatMarche);
    EtatEnum getEtat() { return DEMARRAGE; }
    void setup();
    IEtat* loop(unsigned long millis);
    void onEnter(unsigned long millis);

};

#endif

