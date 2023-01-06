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
    Definition de l'état Marche
*/
class EtatMarche : public IEtat
{
    IEtat* etatArret;
public:
    EtatMarche(IEtat* etatArret, Relays* relays);
    EtatEnum getEtat() { return MARCHE; }
    void setup();
    IEtat* loop(unsigned long millis);
    IEtat* marcheArretClick(unsigned long ms);
    void onEnter(unsigned long millis);
    void onLeave(unsigned long millis);
};

#endif

