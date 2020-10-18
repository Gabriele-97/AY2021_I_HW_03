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
#define IDLE 1
#define BLUERECEIVED 5

CY_ISR(Custom_TIMER_ISR)
{
    // interrupt is verified
    Timer_ReadStatusRegister();
    // return to first state
    if(state != IDLE && state!= BLUERECEIVED)
        flag_timer = 1;
    
    
}
