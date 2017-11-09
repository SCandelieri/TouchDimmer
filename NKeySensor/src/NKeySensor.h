/*
 * NKeySensor.h - Library for controlling a n Key Detector.
 * Created by Santiago G. Candelieri, November 8, 2017.
 * Released into the public domain.
 */

#ifndef NKeySensor_h
#define NKeySensor_h

#include "Arduino.h"

class NKeySensor
{
	private:
		int *pins;
		int numberOfPins;

	public:
		NKeySensor(int pins[], int numberOfPins);
		int *GetPins();
		int GetNumberOfPins();
		int GetPressedKey();
};

#endif