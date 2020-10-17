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
#include "isr_UART.h"


CY_ISR(Custom_UART_ISR){
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY){
        received = UART_ReadRxData();
        Timer_WriteCounter(MAX);
    }
}
/* [] END OF FILE */
