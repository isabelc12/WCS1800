#include <Arduino.h>
#include "WCS1800.h"

WCS1800::WCS1800(uint8_t pin, float V_A, float Vzero, int frequency) //Vzer0=2.5
{
  analogPin=pin;
  sensitivity=V_A; //sensitivity in [Volts/Amps]
  zero=Vzero;
  freq=frequency;
}

int WCS1800::calibrate(){
  uint16_t Aout = 0;
  int i=0;
  for (i=0; i<20; i++){
    Aout+=analogRead(analogPin);
  }
  zeroRead = Aout/20;
  return zeroRead;
}

float WCS1800::getVout()
{
  float vout = 0;
  vout=analogRead(analogPin);
  float V = vout*zero/zeroRead;
  return V;
}

float WCS1800::getDC(float Vo)
{
  float I=(Vo-zero);
  I=I/sensitivity;
  return I;
}

float WCS1800::getAC()
{
  uint32_t final_time=1000000/freq;
  uint32_t start_time=micros();
  float maxCurrent=0;
  float minCurrent=1024;
  float Current=0;

while((micros()-start_time)<final_time){
  Current=analogRead(analogPin);
  if(Current>maxCurrent){
  maxCurrent=Current;
  }
  if(Current<minCurrent){
  minCurrent=Current;
}}
    float Iac=(((maxCurrent-minCurrent)*2.5/zeroRead)*0.707/2)/sensitivity;
    return Iac;
}
