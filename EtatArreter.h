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
	EtatArreter(Relays* relays)
	{
		this->relays = relays;
	}

	void setup()
	{
	}

	IEtat* loop(unsigned long millis)
	{
		return NULL;
	}

	EtatEnum getEtat()
	{
		return ARRETER;
	}

	IEtat* marcheArretClick(unsigned long ms)
	{
		Serial.println("EtatArreter::marcheArretClick()");
		return this->etatDemarrage;
	}

	void setEtatDemarrage(IEtat* etatDemarrage) 
	{
		this->etatDemarrage = etatDemarrage;
	}
};

#endif

