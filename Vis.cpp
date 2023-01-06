// 
// 
// 

#include "Vis.h"
#include <Arduino.h>


Vis::Vis(int pin)
{
	this->pin = pin;
}

void Vis::setup()
{
	pinMode(this->pin, OUTPUT); // bleu
	rapportCyclic = new RapportCyclic(3000, 1.0, this->pin);
}

void Vis::on()
{
	if (!isOn) {
		this->isOn = true;
		Serial.println("vis turn on");
		rapportCyclic->enable();
	}
}

void Vis::off()
{
	if (isOn) {
		this->isOn = false;
		Serial.println("vis turn off");
		rapportCyclic->disable();
	}
}

void Vis::loop(unsigned long ms)
{
	rapportCyclic->loop(ms);
}

void Vis::setRapport(float rapport)
{
	rapportCyclic->setRapport(rapport);
}
