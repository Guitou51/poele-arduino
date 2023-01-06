// 
// 
// 

#include "EtatArreter.h"

EtatArreter::EtatArreter(Relays* relays)
{
	this->relays = relays;
}

void EtatArreter::setup()
{
}

IEtat* EtatArreter::loop(unsigned long millis)
{
	return NULL;
}

EtatEnum EtatArreter::getEtat()
{
	return ARRETER;
}

IEtat* EtatArreter::marcheArretClick(unsigned long ms)
{
	Serial.println("EtatArreter::marcheArretClick()");
	return this->etatDemarrage;
}

void EtatArreter::setEtatDemarrage(IEtat* etatDemarrage)
{
	this->etatDemarrage = etatDemarrage;
}
