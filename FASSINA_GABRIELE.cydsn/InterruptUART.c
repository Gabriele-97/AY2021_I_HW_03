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
#include "InterruptUART.h"
#include "project.h"


CY_ISR(Custom_UART_ISR){
    while(UART_ReadRxStatus() != UART_RX_STS_FIFO_NOTEMPTY);
        received = UART_ReadRxData();
        Timer_WriteCounter(MAX);
    }

/* [] END OF FILE */
