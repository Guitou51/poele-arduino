// Ventillo.h

#ifndef _VENTILLO_h
#define _VENTILLO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

/*
	Gestion du ventillateur
*/
class Ventillo
{
protected:
	int pin;
	boolean isOn = false;

public:
	Ventillo(int pin);
	void setup();
	void on();
	void off();
};

#endif

