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
 private:
	 int pin;
	 boolean isOn = false;
	 RapportCyclic* rapportCyclic;


	 const int PERIODE_VIS = 6000;

 public:
	Vis(int pin);
	void setup();
	void on();
	void off();
	void loop(unsigned long ms);
	void setRapport(float rapport);
};

#endif

