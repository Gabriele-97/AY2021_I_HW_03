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
#ifndef __ISR_UART_H__
    // Header guard
    #define __ISR_UART_H__
    #define MAX 250
    #include "project.h"
    extern uint8_t received;
    /**
    *   \brief ISR Code.
    */
    CY_ISR_PROTO(Custom_UART_ISR);
    
#endif
/* [] END OF FILE */
