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
#include "isr_Timer.h"
#define IDLE 1

CY_ISR(Custom_TIMER_ISR)
{
    // interrupt is verified
    Timer_ReadStatusRegister();
    // return to first state
    state = IDLE;
}
/* [] END OF FILE */
