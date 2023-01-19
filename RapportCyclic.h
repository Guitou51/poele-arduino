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
	RapportCyclic(int periode, float rapport, int pin)
	{
		this->periode = periode;
		this->rapport = rapport;
		this->pin = pin;
	}

	void setPeriode(int periode)
	{
		this->periode = periode;
	}

	void setRapport(float rapport)
	{
		this->rapport = rapport;
	}

	void setDebutMillis(unsigned long debutMillis)
	{
		this->debutMillis = debutMillis;
	}



	bool isWake(unsigned long ms)
	{
		long time_now = (ms - debutMillis) % (periode);

		return (time_now < (rapport* periode));
	}


	void loop(unsigned long ms)
	{
		if (isEnable && this->isWake(ms)) {
			digitalWrite(pin, HIGH);
		}
		else {
			digitalWrite(pin, LOW);
		}
	}

	void enable()
	{
		this->isEnable = true;
	}

	void disable()
	{
		this->isEnable = false;
	}

};

#endif

