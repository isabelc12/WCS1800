#ifndef wcs1800_h
#define wcs1800_h

#include <Arduino.h>

class WCS1800{
public:
  WCS1800(uint8_t pin, float V_A, float Vzero, int frequency); // pin del arduino, sensitividad, voltaje cuando I=0, frecuencia en HZ
  int calibrate();
  float getVout(); //Leer Vout
  float getDC(float Vo); //Obtener corriente directa
  float getAC(); //Obtener corriente alterna

private:
  uint8_t analogPin;
  float sensitivity;
  float zero;
  int zeroRead=0;
  int freq;
};

#endif
