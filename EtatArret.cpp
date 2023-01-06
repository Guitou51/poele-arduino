// 
// 
// 

#include "EtatArret.h"

EtatArret::EtatArret(IEtat* etatArreter, Relays* relays)
{
	this->etatArreter = etatArreter;
	this->relays = relays;
}

void EtatArret::setup()
{
}

IEtat* EtatArret::loop(unsigned long millis)
{
	unsigned long delta = millis - this->enterMillis;

	if (delta > 10000) 
	{
		return this->etatArreter;
	}
	return NULL;
}

EtatEnum EtatArret::getEtat()
{
	return ARRET;
}

void EtatArret::onLeave(unsigned long millis)
{
	this->relays->ventillo->off();
}
