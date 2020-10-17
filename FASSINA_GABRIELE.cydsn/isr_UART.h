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
#ifndef _INTERRUPT_UART_H_
    // Header guard
    #define _INTERRUPT_UART_H_
    #define MAX 250
    #include "project.h"
    extern uint8_t received;
    /**
    *   \brief ISR Code.
    */
    CY_ISR_PROTO(Custom_UART_ISR);
    
#endif
/* [] END OF FILE */
