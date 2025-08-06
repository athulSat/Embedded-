Timer - A peripheral used to perform time-based operations.<br>
It can count clock ticks and generate precise time delays, events, or waveforms.<br>
STM32 timers are highly versatile and can be used for multiple purposes.<br>
<br>
**Upcounting Mode** -<br>
Timer counts from 0 to a predefined value (ARR - Auto Reload Register) and overflows.<br>
Useful for generating delays or periodic events.<br>
<br>
**PWM Mode (Pulse Width Modulation)** -<br>
Used to generate analog-like signals for motor control, LED dimming, etc.<br>
The duty cycle and frequency can be configured via CCR and ARR values.<br>
<br>
**Input Capture Mode** -<br>
Used to measure the duration or frequency of external signals.<br>
Captures timer value when a signal edge (rising/falling) is detected on a pin.<br>
<br>
**Output Compare Mode** -<br>
Compares timer value with a predefined value and triggers an event or toggle an output pin.<br>
Useful for generating precise digital waveforms or timed actions.<br>
