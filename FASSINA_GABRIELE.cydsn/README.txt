Code by Gabriele Fassina
Assignment 3

The provided code is intended to switch the colors of an RGB LED according to 
the RGB pattern that is provided via UART. as the code is written, it is possible
both to send all carachters with just one send or, alternatively, one by one. 
RMK: the code is unguided in case each character is introduced but the removal of 
the comments in the "driver.c" function to uart_putstring functions, allows the
user to be "more guided"  in this latter option. However, being the 
uart_putstring a blocking function, it causes problems in the current version.

At the initialization, the RGB led is off and the user is asked to introduce 
the pattern. when a byte is received, the timer period is restarted so that the 
timer will cause an interrupt only when we wait more than 5 seconds between
two subsequent bytes. 

by digiting v the GUI interface is enabled.