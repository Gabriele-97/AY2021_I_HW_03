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

/*================================================
                        READ ME
this function  checks when a new data has been received (i.e. when the
flag is set to one by the UART ISR function) and proceed the information.
in particular it makes the finite state machine pass from one state to the other 
as soon as a character is received. Furthermore it controls the correctness of
the header and the tail. Finally it sets the values of red, green and blue channels
that are updated after the tail has been received.
RMK uart_putstring functions are commented because they should be included only
to guide the user in case bytes are introduced one to one. the code works also
without them but their introduction makes everything clearer for users
==============================================================*/

#include "project.h"
#include "driver.h"

// definition of the states
#define IDLE 1
#define HEADER 2
#define REDRECEIVED 3
#define GREENRECEIVED 4
#define BLUERECEIVED 5
#define MAX 250

/* this function is aimed to set the PWM parameters needed to obtain the color specified*/
    uint8_t state;
    uint8_t received;
    char flag;
    char flag_timer;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    
    

void RGBLed_WriteColor(){
    
            switch (state){
                
                case IDLE:
                if (flag == 1){
                    if(received == 0xA0){
                        //UART_PutString("inserisci RGB rosso\n");
                        flag = 0;
                        state++;
                      }
                    /*else 
                        UART_PutString("header errato");*/
                }
                break;
                
                case HEADER:
                if (flag == 1){
                    red = received;
                    //UART_PutString("inserisci RGB verde\n");
                    flag = 0;
                    state++;
                }
                 break;
                        
                case REDRECEIVED:
                if (flag == 1){
                   green = received;
                    // UART_PutString("inserisci RGB blu\n");
                    flag = 0;
                    state++;
                }
                
                    break;  
                        
                case GREENRECEIVED:
                if (flag == 1){
                blue = received;
                // UART_PutString("inserisci tail code\n");
                flag = 0;
                state++;
                }
                    break;        
                
                case BLUERECEIVED:
                if (flag == 1){
                    if(received == 0xC0){
                        PWM_RG_WriteCompare1(red);
                        PWM_RG_WriteCompare2(green);
                        PWM_B_WriteCompare(blue);
                        //UART_PutString("Inserisci Header\n");
                        flag =0;
                        state = IDLE;
                    }
                    //else 
                     //   UART_PutString("tail errato");
                }
                break;
            }
            
/*   this part of the code is used to enable the GUI whenever v is received*/     
   if (flag == 1){ 
    if (received == 'v'){
        UART_PutString("RGB LED Program $$$");
        flag =0;}
}
/* this part of the code is used to restart the color setting if more tha 5 seconds have passed*/
    if (flag_timer ==1){
        state = IDLE;
        //UART_PutString("tempo scaduto");
        flag_timer =0;
    }
}

            

/* [] END OF FILE */
