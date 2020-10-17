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
#include "project.h"
#include "isr_Timer.h"
#include "isr_UART.h"
#include "driver.h"

#define IDLE 1
#define HEADER 2
#define REDRECEIVED 3
#define GREENRECEIVED 4
#define BLUERECEIVED 5
#define TAIL 6

CY_ISR(Custom_TIMER_ISR); 
CY_ISR(Custom_UART_ISR); 
void RGBLed_WriteColor();


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_timer_StartEx(Custom_TIMER_ISR);
    Timer_Start();
    isr_UART_StartEx(Custom_UART_ISR);
    UART_Start();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        RGBLed_WriteColor();
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
