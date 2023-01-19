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
	Bougie(int pin)
	{
		this->pin = pin;
	}

	// appeler dans le setup
	void setup()
	{
		pinMode(this->pin, OUTPUT);
	}

	//allumer la bougie
	void on()
	{
		if (!isOn) {
			this->isOn = true;
			Serial.println("bougie turn on");
			digitalWrite(this->pin, HIGH);
		}
	}

	// éteindre la bougie
	void off()
	{
		if (isOn) {
			this->isOn = false;
			Serial.println("bougie turn off");
			digitalWrite(this->pin, LOW);
		}
	}

};


#endif

