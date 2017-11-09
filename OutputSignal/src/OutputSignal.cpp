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
	delay(ms * dutyCycle);
	this->SetOn(false);
	delay(ms * (1 - dutyCycle));
}