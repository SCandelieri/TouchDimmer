#include <OutputSignal.h>

OutputSignal led(13);

void setup()
{

}

void loop()
{
  led.Toggle();
  delay(1000);
}