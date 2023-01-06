// 
// 
// 

#include "RapportCyclic.h"

RapportCyclic::RapportCyclic(int periode, float rapport, int pin)
{
	this->periode = periode;
	this->rapport = rapport;
	this->pin = pin;
}

void RapportCyclic::setPeriode(int periode)
{
	this->periode = periode;
}

void RapportCyclic::setRapport(float rapport)
{
	this->rapport = rapport;
}

void RapportCyclic::setDebutMillis(unsigned long debutMillis)
{
	this->debutMillis = debutMillis;
}

bool RapportCyclic::isWake(unsigned long ms)
{
	long time_now = (ms - debutMillis) % (periode);

	return (time_now < (rapport * periode));
}

void RapportCyclic::enable()
{
	this->isEnable = true;
}

void RapportCyclic::loop(unsigned long ms)
{
	if (isEnable && this->isWake(ms)) {
		digitalWrite(pin, HIGH);
	}
	else {
		digitalWrite(pin, LOW);
	}
}

void RapportCyclic::disable()
{
	this->isEnable = false;
}
