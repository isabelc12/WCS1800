# WCS1800

A WCS1800 is an analog Hall effect sensor, that deliver a measure by means of voltage. 

![wcs 1800 specifications](https://user-images.githubusercontent.com/36057481/37062708-41545b76-2165-11e8-9dcb-40e44ae11cf3.JPG)

## Attributes

* **analogPin:** This value store the current voltage signal that returns the WCS1800.
* **sensitivity:** This value store the sensitivity expressed in mV/A of the WCS1800.
* **zero:** This value store the returned voltage by the WCS1800 when the current is aproximately 0.

## Methods

* **WCS1800:** Constructor class, takes the value of the analogPin as parameter.
* **getVout:** Gets the voltage from 0 to 5 v, where 0 v translates 0 A and 5 v translates 35 A 
* **getDC:** Get the DC current perceived thanks to the hall effect inside the WCS1800.
* **getAC:** Get the AC current approximation based on the DC current.
