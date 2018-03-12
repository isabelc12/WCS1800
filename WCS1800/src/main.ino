#include <Arduino.h>
#include <WCS1800.h>

WCS1800 currentSensor(0,0.06,2.5,60);

void setup()
{
  Serial.begin(9600);
  currentSensor.calibrate();
}

void loop()
{
  float Voltage = currentSensor.getVout();
  float Idc = currentSensor.getDC(Voltage);
  float Iac = currentSensor.getAC();
  Serial.println(String("Vout: ")+Voltage);
  Serial.println(String("DC current: ")+Idc);
  Serial.println(String("AC current: ")+Iac);
  delay(500);
}
