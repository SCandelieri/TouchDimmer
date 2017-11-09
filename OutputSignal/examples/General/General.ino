#include <OutputSignal.h>

OutputSignal led(13);

void setup()
{

}

void loop()
{
  if(!led.IsOn())
    led.SetOn(true);
  delay(1000);
  if(led.GetPin() == 13)
    led.SetOn(false);
  delay(1000);
}