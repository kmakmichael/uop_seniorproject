

/**
 * main.c
 *
 * /* Generates 10KHz and 50% duty cycle on PF2 pin of TM4C123 Tiva C Launchpad */
/* PWM1 module and PWM generator 3 of PWM1 module is used
 */

//#include "TM4c123gh6pm.h"
#define SYSCTL_RCGCGPIO_R (*(( volatile unsigned long *)0x400FE608 ) )

#define GPIO_PORTF_DATA_R (*(( volatile unsigned long *)0x40025038 ) )
#define GPIO_PORTF_LOCK_R (*(( volatile unsigned long *)0x40025520 ) )
#define GPIO_PORTF_CR_R   (*(( volatile unsigned long *)0x40025524 ) )
#define GPIO_PORTF_PUR_R  (*(( volatile unsigned long *)0x40025510 ) )
#define GPIO_PORTF_DIR_R  (*(( volatile unsigned long *)0x40025400 ) )
#define GPIO_PORTF_DEN_R  (*(( volatile unsigned long *)0x4002551C ) )

#define GPIO_PORTB_DATA_R (*(( volatile unsigned long *)0x400053FC ) )
#define GPIO_PORTB_LOCK_R (*(( volatile unsigned long *)0x40005520 ) )
#define GPIO_PORTB_CR_R   (*(( volatile unsigned long *)0x40005524 ) )
#define GPIO_PORTB_PUR_R  (*(( volatile unsigned long *)0x40005510 ) )
#define GPIO_PORTB_DIR_R  (*(( volatile unsigned long *)0x40005400 ) )
#define GPIO_PORTB_DEN_R  (*(( volatile unsigned long *)0x4000551C ) )

#define GPIO_PORTE_DATA_R (*(( volatile unsigned long *)0x400243FC ) )
#define GPIO_PORTE_LOCK_R (*(( volatile unsigned long *)0x40024520 ) )
#define GPIO_PORTE_CR_R   (*(( volatile unsigned long *)0x40024524 ) )
#define GPIO_PORTE_PUR_R  (*(( volatile unsigned long *)0x40024510 ) )
#define GPIO_PORTE_DIR_R  (*(( volatile unsigned long *)0x40024400 ) )
#define GPIO_PORTE_DEN_R  (*(( volatile unsigned long *)0x4002451C ) )

#define GPIO_PORTD_DATA_R (*(( volatile unsigned long *)0x400073FC ) )
#define GPIO_PORTD_LOCK_R (*(( volatile unsigned long *)0x40007520 ) )
#define GPIO_PORTD_CR_R   (*(( volatile unsigned long *)0x40007524 ) )
#define GPIO_PORTD_PUR_R  (*(( volatile unsigned long *)0x40007510 ) )
#define GPIO_PORTD_DIR_R  (*(( volatile unsigned long *)0x40007400 ) )
#define GPIO_PORTD_DEN_R  (*(( volatile unsigned long *)0x4000751C ) )


int main(void)
{
    //SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock for PORTF
    SYSCTL_RCGCGPIO_R |= 0x3A;  // Enable clock for PORTA,B,E,F
    GPIO_PORTF_LOCK_R  |= 0x4C4F434;
   // GPIO_PORTF_LOCK_R  |= 0x4C4F434B;
    GPIO_PORTF_CR_R  |= 0x01;
    GPIO_PORTF_DIR_R  |= 0x0E;  // Configure PORTF Pin1, 2 and 3 digital output pins
    GPIO_PORTF_PUR_R  |= 0x10;
    GPIO_PORTF_DEN_R  |= 0x0E;  // Enable PORTF Pin1, 2 and 3 as a digital pins

   // GPIO_PORTB_LOCK_R  |= 0x4C4F434B;
    GPIO_PORTB_CR_R  |= 0x01;
    GPIO_PORTB_DIR_R  |= 0x0E;  // Configure PORTF Pin1, 2 and 3 digital output pins
    GPIO_PORTB_PUR_R  |= 0x10;
    GPIO_PORTB_DEN_R  |= 0x0E;  // Enable PORTF Pin1, 2 and 3 as a digital pins

  //  GPIO_PORTE_LOCK_R  |= 0x4C4F434;
    GPIO_PORTE_CR_R  |= 0x01;
    GPIO_PORTE_DIR_R  |= 0x0E;  // Configure PORTF Pin1, 2 and 3 digital output pins
    GPIO_PORTE_PUR_R  |= 0x10;
    GPIO_PORTE_DEN_R  |= 0x0E;  // Enable PORTF Pin1, 2 and 3 as a digital pins

  //  GPIO_PORTA_LOCK_R  |= 0x4C4F434;
    GPIO_PORTD_CR_R  |= 0x01;
    GPIO_PORTD_DIR_R  |= 0x0E;  // Configure PORTF Pin1, 2 and 3 digital output pins
    GPIO_PORTD_PUR_R  |= 0x10;
    GPIO_PORTD_DEN_R  |= 0x0E;  // Enable PORTF Pin1, 2 and 3 as a digital pins

    GPIO_PORTF_DATA_R |= 0x02; // turn off red LED
    GPIO_PORTB_DATA_R |= 0x02; // turn off red LED
    GPIO_PORTE_DATA_R &= 0x00; // turn off red LED
    GPIO_PORTD_DATA_R &= 0x00; // turn off red LED

    int x = 2;

    int y = 0;


    if(x==0)  //letting cable out
    {
        GPIO_PORTF_DATA_R &= 0x00; // turn off PF1
        GPIO_PORTB_DATA_R |= 0x02; // turn on PB1
        GPIO_PORTE_DATA_R |= 0x02; // turn on PE1
        GPIO_PORTD_DATA_R &= 0x00; // turn off PD1
       // delay(1000);    // delay for one second
        GPIO_PORTF_DATA_R &= 0x00; // turn off PF1
        GPIO_PORTB_DATA_R &= 0x00; // turn off PB1
        GPIO_PORTE_DATA_R &= 0x00; // turn off PE1
        GPIO_PORTD_DATA_R &= 0x00; // turn off PD1
    }

    else if (x==1)  //braking
    {
        GPIO_PORTF_DATA_R &= 0x00; // turn off PF1
        GPIO_PORTF_DATA_R |= 0x02; // turn on PF1
        GPIO_PORTB_DATA_R &= 0x00; // turn off PB1
        GPIO_PORTE_DATA_R &= 0x00; // turn off PE1
        GPIO_PORTD_DATA_R |= 0x02;; // turn on PD1


        GPIO_PORTF_DATA_R &= 0x00; // turn off PF1
        GPIO_PORTB_DATA_R &= 0x00; // turn off PB1
        GPIO_PORTE_DATA_R &= 0x00; // turn off PE1
        GPIO_PORTD_DATA_R &= 0x00; // turn off PD1
    }






    else if (x==2)   //braking then letting out then braking etc...
    {

    //    GPIO_PORTF_DATA_R &= 0x00; // turn off PF1
        GPIO_PORTF_DATA_R |= 0x02; // turn on PF1   //brake
        GPIO_PORTE_DATA_R &= 0x00; // turn off PE1
        GPIO_PORTD_DATA_R |= 0x02;; // turn on PD1
        GPIO_PORTB_DATA_R &= 0x00; // turn off PB1


        for(y=0; y < 1*3000000; y=y+1);  //delay about 2 second
            {
            }

        GPIO_PORTB_DATA_R |= 0x02; // turn on PB1   //release
        GPIO_PORTD_DATA_R &= 0x00; // turn off PD1
        GPIO_PORTE_DATA_R |= 0x02; // turn on PE1
        GPIO_PORTF_DATA_R &= 0x00; // turn off PF1


        for(y=0; y < 1*3000000; y=y+1);  //delay about 2 second
            {
            }

        GPIO_PORTF_DATA_R |= 0x02; // turn on PF1   //brake
        GPIO_PORTE_DATA_R &= 0x00; // turn off PE1
        GPIO_PORTD_DATA_R |= 0x02;; // turn on PD1
        GPIO_PORTB_DATA_R &= 0x00; // turn off PB1

        for(y=0; y < 1*3000000; y=y+1);  //delay about 2 second
            {
            }
        GPIO_PORTB_DATA_R |= 0x02; // turn on PB1   //release
        GPIO_PORTD_DATA_R &= 0x00; // turn off PD1
        GPIO_PORTE_DATA_R |= 0x02; // turn on PE1
        GPIO_PORTF_DATA_R &= 0x00; // turn off PF1
        for(y=0; y < 1*3000000; y=y+1);  //delay about 2 second
            {
            }


        GPIO_PORTF_DATA_R |= 0x02; // turn off red LED
        GPIO_PORTB_DATA_R |= 0x02; // turn off red LED
        GPIO_PORTE_DATA_R &= 0x00; // turn off red LED
        GPIO_PORTD_DATA_R &= 0x00; // turn off red LED
    }

    else

        for(y=0; y < 1*3000000; y=y+1);  //delay about 2 second
            {
            }

	return 0;
}


