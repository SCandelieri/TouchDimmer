/*
 * OutputSignal.cpp - Library for controlling a digital output signal.
 * Created by Santiago G. Candelieri, November 8, 2017.
 * Released into the public domain.
 */

#include "Arduino.h"
#include "OutputSignal.h"

OutputSignal::OutputSignal(int pin)
{
	this->pin = pin;
	pinMode(this->pin, OUTPUT);
	this->SetOn(false);
}

void OutputSignal::Write()
{
	digitalWrite(this->pin, this->on);
}

bool OutputSignal::IsOn()
{
	return this->on;
}

void OutputSignal::SetOn(bool isOn)
{
	this->on = isOn;
	this->Write();
}

int OutputSignal::GetPin()
{
	return this->pin;
}

void OutputSignal::Toggle()
{
	this->SetOn(!this->on);
}

void OutputSignal::PWM(unsigned long ms, float dutyCycle)
{
	this->SetOn(true);
	delay(Round((float)ms * dutyCycle));
	this->SetOn(false);
	delay(Round((float)ms * (1.0f - dutyCycle)));
}

void OutputSignal::PWMMicroseconds(unsigned int us, float dutyCycle)
{
	this->SetOn(true);
	delayMicroseconds(Round((float)us * dutyCycle));
	this->SetOn(false);
	delayMicroseconds(Round((float)us * (1.0f - dutyCycle)));
}

unsigned long OutputSignal::Round(float number)
{
	int integerPart = (int)number;
	float decimalPart = number - integerPart;
	return (decimalPart > 0.5f) ? (integerPart + 1) : integerPart;
}