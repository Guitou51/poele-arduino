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
	Ventillo(int pin)
	{
		this->pin = pin;
	}

	void setup()
	{
		pinMode(this->pin, OUTPUT);
	}

	void on()
	{
		if (!isOn) {
			this->isOn = true;
			Serial.println("ventillo turn on");
			digitalWrite(this->pin, HIGH);
		}
	}

	void off()
	{
		if (isOn) {
			this->isOn = false;
			Serial.println("ventillo turn off");
			digitalWrite(this->pin, LOW);
		}
	}
};

#endif

