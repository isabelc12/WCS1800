# WCS1800

A WCS1800 is an analog Hall effect sensor, that delivers a measure by means of voltage. 

![wcs 1800 specifications](https://user-images.githubusercontent.com/36057481/37062708-41545b76-2165-11e8-9dcb-40e44ae11cf3.JPG)

## Attributes

* **analogPin:** Arduino Analog Pin where the WCS1800 is connected.
* **sensitivity:** This value store the sensitivity expressed in mV/A of the WCS1800.
* **zeroRead:** Stores the value read by Arduino when the current is 0A, set between 0 and 1024.
* **zero:** This value is the Vout when the current is 0A, (Vcc/2).
* **freq:** Line power frequency, normally 60Hz.

## Methods

* **WCS1800:** Constructor class, takes the value of the analogPin, sensitivity, zero and frequency as parameters.
* **Calibrate:** Sets the value of zeroRead, calibrates the sensor read when current is 0A.
* **getVout:** Gets the voltage from 0 to 5 v, where 0 v translates 0 A and 5 v translates 35 A 
* **getDC:** Gets the DC current perceived thanks to the hall effect inside the WCS1800.
* **getAC:** Gets the AC current approximation.
