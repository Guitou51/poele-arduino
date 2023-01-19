// Relays.h

#ifndef _RELAYS_h
#define _RELAYS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Vis.h"
#include "Bougie.h"
#include "Ventillo.h"

/*
	regroupe les relays/sorties
*/
class Relays {

public:
	Relays(Vis* vis, Bougie* bougie, Ventillo* ventillo)
	{
		this->vis = vis;
		this->bougie = bougie;
		this->ventillo = ventillo;
	}


	Vis* vis;
	Bougie* bougie;
	Ventillo* ventillo;

	void loop(unsigned long ms) {
		vis->loop(ms);
	}
};


#endif

