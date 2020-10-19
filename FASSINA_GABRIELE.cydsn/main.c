/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*==========================================
            CODE EXPLANATION (READ ME)
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

================================================================================*/

/*=================================
         HEADER FILES AND DEFINE
====================================*/
#include "project.h" 
#include "InterruptTimer.h"
#include "InterruptUART.h"
#include "driver.h"

#define IDLE 1

/*=================================
initialization of global variables
==================================*/

uint8_t state = IDLE;
uint8_t received;
char flag_timer =0;
char flag = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_RG_Start(); // PWM for red and green activation
    PWM_B_Start(); // PWM for blue activation
    UART_Start(); //UART activation
    isr_UART_StartEx(Custom_UART_ISR); //the interrupt on uart is triggered when data are received.
    Timer_Start(); //timer activation
    isr_timer_StartEx(Custom_TIMER_ISR); //the interrupt on timer is triggered when it completes a period of 5s 
    
    
    for(;;)
    {
      RGBLed_WriteColor();
   
    }
}

/* [] END OF FILE */
