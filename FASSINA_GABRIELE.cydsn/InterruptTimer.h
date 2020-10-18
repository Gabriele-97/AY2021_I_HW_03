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

#ifndef __INTERRUPT_TIMER_H__
    // Header guard
    #define __INTERRUPT_TIMER_H__
    #include "project.h"
    extern uint8_t state;
    extern char flag_timer;
    
    CY_ISR_PROTO(Custom_TIMER_ISR);;
    
#endif
