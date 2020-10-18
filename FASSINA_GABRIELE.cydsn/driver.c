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
    uint8_t received;
    char flag;
    char flag_timer;
    

void RGBLed_WriteColor(){
    
            switch (state){
                
                case IDLE:
                if (flag == 1){
                    if(received == 0xA0){
                        UART_PutString("inserisci RGB rosso\n");
                        state++;}
                    else if (received == 'v'){
                        UART_PutString("RGB LED Program $$$");
                    }
                        
                    else 
                        UART_PutString("header errato");
                }
                flag = 0;
                    break;
                
                case HEADER:
                if (flag == 1){
                    if(received < 0x00 || received>0xff)
                        UART_PutString("valore errato");
                    else{
                        PWM_RG_WriteCompare1(received);
                        UART_PutString("inserisci RGB verde\n");
                        state++;}
                        
                }
                flag =0;
                    break;
                        
                case REDRECEIVED:
                if (flag == 1){
                    if(received < 0 || received>255)
                        UART_PutString("valore errato");
                    else{
                        PWM_RG_WriteCompare2(received);
                        UART_PutString("inserisci RGB blu\n");
                        state++;}
                        
                }
                flag = 0;
                    break;  
                        
                case GREENRECEIVED:
                if (flag == 1){
                    if(received < 0 || received>255)
                        UART_PutString("valore errato");
                                   
                    else{
                        PWM_B_WriteCompare(received);
                        UART_PutString("inserisci tail code\n");
                        state++;}
                    }
                    
                flag = 0;
                    break;        
                
                case BLUERECEIVED:
                if (flag == 1){
                    if(received == 0xC0){
                        UART_PutString("Inserisci Header\n");
                        state = IDLE;
                    }
                    else 
                        UART_PutString("tail errato");
                }
                flag =0;
                    break;   
              
            }
            
    if (flag_timer == 1 ){
        UART_PutString("tempo scaduto! inserisci header\n");
        flag_timer = 0;
        state = IDLE;
    }
}
/* [] END OF FILE */
