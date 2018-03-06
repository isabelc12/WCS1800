#include <Arduino.h>
#include "WCS1800.h"

WCS1800::WCS1800(uint8_t pin, float V_A, float Vzero) //Vzer0=2.5
{
  analogPin=pin;
  sensitivity=V_A; //sensitivity in [Volts/Amps]
  zero=Vzero;
}

float WCS1800::getVout()
{
  int scale = 512; //calibracion, lectura serial cuando I=0
  float vout = 0;
  vout=analogRead(analogPin);
  //Serial.println(vout);
  float V = vout*zero/scale;
  return V;
}

float WCS1800::getDC(float Vo)
{
  float I=(Vo-zero);
  I=I/sensitivity;
  return I;
}

float WCS1800::getAC(float Vo)
{
  float Iac=(Vo-zero)/sensitivity*0.707;
  return Iac;
}
