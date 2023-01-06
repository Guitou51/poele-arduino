#include "EtatManager.h"

void EtatManager::marcheArretClick(unsigned long ms)
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

EtatManager::EtatManager(Relays* relays, Afficheur* display)
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



void EtatManager::loop(unsigned long ms) {
    IEtat* next = etatCourant->loop(ms);
    this->relays->loop(ms);

    if (next != NULL)
    {
        changeEtat(next, ms);
    }
    this->display->loop(etatCourant->getEtat(), ms);
}

void EtatManager::changeEtat(IEtat* next, unsigned long ms)
{
    printChangeEtat(next, ms);
    etatCourant->leave(ms);
    next->enter(ms);
    etatCourant = next;
}

void EtatManager::printChangeEtat(IEtat* next, unsigned long ms)
{
    Serial.print("Changement etat: ");
    Serial.print(next->getEtat());
    Serial.print(", ");
    Serial.print(ms);
    Serial.println("ms");
}

/*
EtatEnum EtatManager::getCurrentEtat()
{
    return this->etatCourant->getEtat();
}
*/