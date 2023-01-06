// Bougie.h

#ifndef _BOUGIE_h
#define _BOUGIE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

/*
	Gestion de la bougie
*/
class Bougie
{
private:
	int pin;
	// si la bougie est allumé
	boolean isOn = false;

public:
	// Constructeur
	Bougie(int pin);

	// appeler dans le setup
	void setup();

	//allumer la bougie
	void on();

	// éteindre la bougie
	void off();
};


#endif

