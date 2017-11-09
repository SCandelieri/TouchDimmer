/*
 * OutputSignal.h - Library for controlling a digital output signal.
 * Created by Santiago G. Candelieri, November 8, 2017.
 * Released into the public domain.
 */

#ifndef OutputSignal_h
#define OutputSignal_h

#include "Arduino.h"

class OutputSignal
{
	private:
		bool on;
		int pin;
		void Write();
	
	public:
		OutputSignal(int pin);
		bool IsOn();
		void SetOn(bool isOn);
		int GetPin();
		void Toggle();
		void PWM(unsigned long ms, float dutyCycle);
};

#endif