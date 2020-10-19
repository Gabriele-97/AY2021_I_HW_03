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
#include "InterruptTimer.h"
uint8_t state;

CY_ISR(Custom_TIMER_ISR)
{
    
    // interrupt is verified
    Timer_ReadStatusRegister();
    flag_timer =1; //when this flag is set to one the state returns to IDLE
 
}
