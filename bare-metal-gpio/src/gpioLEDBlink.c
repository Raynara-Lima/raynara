/*
 * =====================================================================================
 *
 *       Filename:  gpioLEDBlink.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/05/2016 12:15:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (), helderhdw@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "gpioLED.h"

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
#define MSEG                           (0x3FFFFFF)

/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
static void Delay(unsigned int count);


/*FUNCTION*-------------------------------------------------------
*
* Function Name : main
* Comments      :
*END*-----------------------------------------------------------*/
int valuepin(int pin);
int main() {
    int pin_out = 23, pin_in = 12;
    /* configure gpio pin for the blue LED control. */
    ledInit(pin_out, DIR_OUTPUT);
    ledInit(pin_in, DIR_INPUT);

    while(TRUE){
        /* Change the state of the blue LED. */     
        if(valuepin(pin_out)){
            
            ledToggle(pin_out);
        }
        

        /* Pause for 500 ms */
        Delay(MSEG);

    }

    return(0);
} 

/*FUNCTION*-------------------------------------------------------
*
* Function Name : Delay
* Comments      :
*END*-----------------------------------------------------------*/
static void Delay(volatile unsigned int count){
    while(count--);
      asm("   nop");
}

int valuepin(int pin){
    int auxiliar;
    int *aux = (int*)(GPIO_INSTANCE_ADDRESS + GPIO_DATAIN);
    auxiliar = *aux;
    
    if(auxiliar & (1 << pin)){ 
        return PIN_HIGH;
    }
    else{ 
        return PIN_LOW;
    }
}
