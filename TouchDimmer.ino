#include "OutputSignal.h"
#include "NKeySensor.h"

int pins[] = {8, 9, 10, 11};
OutputSignal lamp(12);
NKeySensor key4TouchDetector(pins, sizeof(pins) / sizeof(pins[0]));
int currentKey = -1;
int previousKey = 0;
int period = 20;

void setup()
{

}

void loop()
{
	currentKey = key4TouchDetector.GetPressedKey();
	if (currentKey != -1)
	{
		previousKey = currentKey;
	}
	lamp.PWM(period, (1.0f - (float)previousKey / 3.0f));
}