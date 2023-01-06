// 
// 
// 

#include "Ventillo.h"

Ventillo::Ventillo(int pin)
{
	this->pin = pin;
}

void Ventillo::setup()
{
	pinMode(this->pin, OUTPUT);
}

void Ventillo::on()
{
	if (!isOn) {
		this->isOn = true;
		Serial.println("ventillo turn on");
		digitalWrite(this->pin, HIGH);
	}
}

void Ventillo::off()
{
	if (isOn) {
		this->isOn = false;
		Serial.println("ventillo turn off");
		digitalWrite(this->pin, LOW);
	}
}