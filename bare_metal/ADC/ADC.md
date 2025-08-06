ADC - Analog to Digital Converter.<br>
It converts an analog voltage signal into a corresponding digital value.<br>
Useful when reading sensors like temperature, potentiometers, light sensors, etc.<br>
STM32 ADC supports various modes to suit different applications.<br>
<br>
**Single Conversion Mode** -<br>
Converts the input channel once and stops.<br>
Typically triggered by software or an external event.<br>
Used when sampling occasionally or manually.<br>
<br>
**Continuous Conversion Mode** -<br>
Continuously converts the selected channel without stopping.<br>
Used when constant monitoring of an analog signal is needed.<br>
Requires fewer CPU interactions for repeated measurements.<br>
<br>
