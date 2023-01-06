// Vis.h

#ifndef _VIS_h
#define _VIS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "RapportCyclic.h"

/*
	Gestion de la Vis
*/
class Vis
{
 protected:
	 int pin;
	 boolean isOn = false;
	 RapportCyclic* rapportCyclic;

 public:
	Vis(int pin);
	void setup();
	void on();
	void off();
	void loop(unsigned long ms);
	void setRapport(float rapport);
};

#endif

