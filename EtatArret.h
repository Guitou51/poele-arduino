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
	Definition de l'�tat Arret
*/
class EtatArret : public IEtat
{
	const int DELAI_ARRET = 5 * 60000; //5 mins
	IEtat* etatArreter;
public:
	EtatArret(IEtat* etatArreter, Relays* relays);
	void setup();
	IEtat* loop(unsigned long millis);
	EtatEnum getEtat();
	void onLeave(unsigned long millis);
};



#endif

