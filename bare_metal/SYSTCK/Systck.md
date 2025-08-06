SysTick - System Timer provided by the Cortex-M core.<br>
It is a 24-bit countdown timer.<br>
Primarily used to generate periodic interrupts.<br>
Commonly configured to create delays or to implement time-based events like RTOS ticks.<br>
In this project, SysTick is used to create accurate time delays.<br>
It runs using the system clock and automatically reloads when it reaches zero.<br>
