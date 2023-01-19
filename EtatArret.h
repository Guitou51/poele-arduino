// EtatArret.h

#ifndef _ETATARRET_h
#define _ETATARRET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "IEtat.h"
#include "EtatArreter.h"

/*
	Definition de l'état Arret
*/
class EtatArret : public IEtat
{
	const int DELAI_ARRET = 5 * 60000; //5 mins
	IEtat* etatArreter;
public:
	EtatArret(IEtat* etatArreter, Relays* relays)
	{
		this->etatArreter = etatArreter;
		this->relays = relays;
	}
	void setup()
	{
	}
	IEtat* loop(unsigned long millis)
	{
		unsigned long delta = millis - this->enterMillis;

		if (delta > DELAI_ARRET)
		{
			return this->etatArreter;
		}
		return NULL;
	}
	EtatEnum getEtat()
	{
		return ARRET;
	}
	void onLeave(unsigned long millis)
	{
		this->relays->ventillo->off();
	}
};



#endif

