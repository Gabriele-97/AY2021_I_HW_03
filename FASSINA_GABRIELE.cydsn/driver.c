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
#include "driver.h"


#define IDLE 1
#define HEADER 2
#define REDRECEIVED 3
#define GREENRECEIVED 4
#define BLUERECEIVED 5
#define TAIL 6
#define MAX 250

/* this function is aimed to set the PWM parameters needed to obtain the patterns specified*/
    uint8_t state;
    uint16_t received;

void RGBLed_WriteColor(){
    
            switch (state){
                
                case IDLE:
                    if(received == 0xA0){
                        state++;
                    }
                    else
                        UART_PutString("header errato");
                    break;
                
                case HEADER:
                    if(received < 0 || received>255){
                        UART_PutString("valore errato");
                    }
                    else{
                        PWM_RG_WriteCompare1(received);
                        state++;}
                    break;
                        
                case REDRECEIVED:
                    if(received < 0 || received>255){
                        UART_PutString("valore errato");
                    }
                    else{
                        PWM_RG_WriteCompare2(received);
                        state++;}
                    break;  
                        
                case GREENRECEIVED:
                    if(received < 0 || received>255){
                        UART_PutString("valore errato");
                    }
                    else{
                        PWM_B_WriteCompare(received);
                        state++;
                    }
                    break;        
                
                case BLUERECEIVED:
                    if(received == 0xC0)
                        state++;
                    else 
                        UART_PutString("tail errato");
                    break;   
                   
            
            }
}
/* [] END OF FILE */
