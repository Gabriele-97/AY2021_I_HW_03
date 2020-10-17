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
#include "InterruptTimer.h"
#include "InterruptUART.h"
#include "driver.h"


#define IDLE 1
#define HEADER 2
#define REDRECEIVED 3
#define GREENRECEIVED 4
#define BLUERECEIVED 5
#define TAIL 6

uint8_t state = IDLE;
uint16_t received;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_RG_Start();
    PWM_B_Start();
    UART_Start();
    isr_UART_StartEx(Custom_UART_ISR);
    Timer_Start();
    isr_TIMER_StartEx(Custom_TIMER_ISR);
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    for(;;)
    {
      RGBLed_WriteColor();
      CyDelay(200);
    }
}

/* [] END OF FILE */
