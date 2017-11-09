#include <OutputSignal.h>

OutputSignal led(13);

void setup()
{

}

void loop()
{
  led.PWM(10, 0.1);
}