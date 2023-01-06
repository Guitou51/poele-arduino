// RapportCyclic.h

#ifndef _RAPPORTCYCLIC_h
#define _RAPPORTCYCLIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class RapportCyclic {
private:
	int periode;
	float rapport;
	int pin;
	unsigned long debutMillis = 0;
	bool isEnable = false;
public:
	RapportCyclic(int periode, float rapport, int pin);
	void setPeriode(int periode);
	void setRapport(float rapport);
	void setDebutMillis(unsigned long debutMillis);


	bool isWake(unsigned long ms);

	void loop(unsigned long ms);

	void enable();
	void disable();
};

#endif

