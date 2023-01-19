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
	Vis(int pin)
	{
		this->pin = pin;
	}

	void setup()
	{
		pinMode(this->pin, OUTPUT); // bleu
		rapportCyclic = new RapportCyclic(PERIODE_VIS, 1.0, this->pin);
	}

	void on()
	{
		if (!isOn) {
			this->isOn = true;
			Serial.println("vis turn on");
			rapportCyclic->enable();
		}
	}

	void off()
	{
		if (isOn) {
			this->isOn = false;
			Serial.println("vis turn off");
			rapportCyclic->disable();
		}
	}

	void loop(unsigned long ms)
	{
		rapportCyclic->loop(ms);
	}

	void setRapport(float rapport)
	{
		rapportCyclic->setRapport(rapport);
	}

};

#endif

