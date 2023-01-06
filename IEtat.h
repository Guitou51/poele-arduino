// IEtat.h

#ifndef _IETAT_h
#define _IETAT_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
#else
    #include "WProgram.h"
#endif
#include "Enum.h"
#include "Relays.h"


class IEtat
{
protected:
    // a quelle ms on est entrée dans l'état
    unsigned long enterMillis;
    // a quelle ms on est sortie de l'état
    unsigned long leaveMillis;

    Relays* relays;
public:
    // configuration de l'état. Est éxécuter une fois au démarrage de l'arduino.
    virtual void setup() = 0;

    // éxecuter a chaque loop. 
    // si return NULL, on reste dans l'état en cours,
    // si return autreEtat, on change d'état
    virtual IEtat* loop(unsigned long millis) = 0;

    // l'état courant
    virtual EtatEnum getEtat() = 0;

    // action éxécuter a l'appui du bouton marche/arret.
    // si return NULL, on reste dans l'état en cours,
    // si return autreEtat, on change d'état
    virtual IEtat* marcheArretClick(unsigned long ms) {
        Serial.println("IEtat::marcheArretClick");
        return NULL;
    }

    // éxecuter a l'entrée dans l'etat. Peut etre surcharger
    virtual void onEnter(unsigned long millis) {

    }

    // éxecuter a la sortie de l'etat. Peut etre surcharger
    virtual void onLeave(unsigned long millis) {

    }

    void enter(unsigned long millis) {
        Serial.print("IEtat::enter: ");
        Serial.print(millis);
        Serial.print("ms ");
        Serial.print(", etat: ");
        Serial.println(getEtatString());
        
        enterMillis = millis;
        this->onEnter(millis);
    }

    void leave(unsigned long millis) {
        Serial.print("IEtat::leave: ");
        Serial.print(millis);
        Serial.print("ms");
        Serial.print(", etat: ");
        Serial.println(getEtatString());
        this->onLeave(millis);
        leaveMillis = millis;
    }
    String getEtatString() {
        return EtatString.getEtat(getEtat());
    }
};

#endif

