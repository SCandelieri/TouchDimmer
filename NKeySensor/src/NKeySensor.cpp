/*
 * NKeySensor.h - Library for controlling a n Key Detector.
 * Created by Santiago G. Candelieri, November 8, 2017.
 * Released into the public domain.
 */

#include "Arduino.h"
#include "NKeySensor.h"

NKeySensor::NKeySensor(int pins[], int numberOfPins)
{
	this->pins = pins;
	this->numberOfPins = numberOfPins;
	for (int i = 0; i < this->GetNumberOfPins(); i++)
	{
		pinMode(pins[i], INPUT);
	}
}

int *NKeySensor::GetPins()
{
	return this->pins;
}

int NKeySensor::GetNumberOfPins()
{
	return this->numberOfPins;
}

int NKeySensor::GetPressedKey()
{
	int i = 0;
	int *pinsPointer = this->pins;
	while (i < this->GetNumberOfPins() && digitalRead(*pinsPointer) != HIGH)
	{
		i++;
		pinsPointer++;
	}
	return (i < this->GetNumberOfPins()) ? i : -1;
}