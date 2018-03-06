#include <Arduino.h>
#include <WCS1800.h>

WCS1800 currentSensor(0,0.06,2.5);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float Voltage = currentSensor.getVout();
  float Idc = currentSensor.getDC(Voltage);
  float Iac = currentSensor.getAC(Voltage);
  Serial.println(String("Vout: ")+Voltage);
  Serial.println(String("DC current: ")+Idc);
  Serial.println(String("AC current: ")+Iac);
  delay(2000);
}
