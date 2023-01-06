// 
// 
// 

#include "Bougie.h"

Bougie::Bougie(int pin)
{
	this->pin = pin;
}

void Bougie::setup()
{
	pinMode(this->pin, OUTPUT);
}

void Bougie::on()
{
	if (!isOn) {
		this->isOn = true;
		Serial.println("bougie turn on");
		digitalWrite(this->pin, HIGH);
	}
}

void Bougie::off()
{
	if (isOn) {
		this->isOn = false;
		Serial.println("bougie turn off");
		digitalWrite(this->pin, LOW);
	}
}
