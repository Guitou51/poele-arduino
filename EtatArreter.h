// EtatArreter.h

#ifndef _ETATARRETER_h
#define _ETATARRETER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "IEtat.h"
#include "EtatDemarrage.h"


/*
	Definition de l'état Arreter
*/
class EtatArreter :public IEtat
{
private:
	IEtat* etatDemarrage;
public:
	EtatArreter(Relays* relays);
	void setup();
	IEtat* loop(unsigned long millis);
	EtatEnum getEtat();
	IEtat* marcheArretClick(unsigned long ms);
	void setEtatDemarrage(IEtat* etatDemarrage);
};

#endif

