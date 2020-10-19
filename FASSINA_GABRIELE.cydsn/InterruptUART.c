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
extern char flag;

CY_ISR(Custom_UART_ISR){
    
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY){     
        received = UART_ReadRxData(); //I save the received byte in a variable
        Timer_WriteCounter(MAX); //i reinitialize the counter of the timer to the max (250)
        flag =1; //This flag means a new data has been received 
      
    }
    }

/* [] END OF FILE */
