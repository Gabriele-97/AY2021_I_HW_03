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
    char correct_string;
    uint8_t rosso;
    uint8_t verde;
    uint8_t blue;
    

void RGBLed_WriteColor(){
    
            switch (state){
                
                case IDLE:
                if (flag == 1){
                    if(received == 0xA0){
                        //UART_PutString("inserisci RGB rosso\n");
                        flag = 0;
                        state++;}
                    //else if (received == 'v'){
                        //UART_PutString("RGB LED Program $$$");
                    }
                        
                    /*else 
                        UART_PutString("header errato");
                }*/
                
                    break;
                
                case HEADER:
                if (flag == 1){
                    if(received < 0x00 || received>0xff)
                        UART_PutString("valore errato");
                    else{
                        rosso = received;
                        //UART_PutString("inserisci RGB verde\n");
                        flag =0;
                        state++;}
                        
                }
                
                    break;
                        
                case REDRECEIVED:
                if (flag == 1){
                    if(received < 0 || received>255)
                        UART_PutString("valore errato");
                    else{
                        verde = received;
                        //UART_PutString("inserisci RGB blu\n");
                        flag = 0;
                        state++;}
                        
                }
                
                    break;  
                        
                case GREENRECEIVED:
                if (flag == 1){
                    if(received < 0 || received>255)
                        UART_PutString("valore errato");
                                   
                    else{
                        blue = received;
                        //UART_PutString("inserisci tail code\n");
                        flag = 0;
                        state++;}
                    }
                    
                
                    break;        
                
                case BLUERECEIVED:
                if (flag == 1){
                    if(received == 0xC0){
                        correct_string =1; 
                        //UART_PutString("Inserisci Header\n");
                        flag =0;
                        state = IDLE;
                    }
                    //else 
                     //   UART_PutString("tail errato");
                
                
                }
                
                    break;   
              
            
            }
            
    if (flag_timer == 1 ){
        UART_PutString("tempo scaduto! inserisci header\n");
        flag_timer = 0;
        state = IDLE;
    }
    
    if (correct_string ==1){
                        PWM_RG_WriteCompare1(rosso);
                        PWM_RG_WriteCompare2(verde);
                        PWM_B_WriteCompare(blue);
                        correct_string =0;
    }
   if (flag == 1){ 
    if (received == 'v')
        UART_PutString("RGB LED Program $$$");
        flag =0;
}
}

/* [] END OF FILE */
