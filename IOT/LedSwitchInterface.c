 //Sample Program 1:  Interfacing LED and Switch to LPC2148 using GPIO pins
   //P0.31 connected to LED - D7 in CPU board(common anode)
   //P1.14 connected to Switch - SW2 in CPU board
#include <lpc214x.h>
#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)
#define SW2 (IO0PIN & (1 << 14))
void delay_ms(unsigned int j);
int main( )
{
 IO0DIR = 1U << 31;
 IO0SET = 1U << 31;
 while(1)
   {
if (!(IO0PIN & (1 << 14)))//(if(!SW2 ) 
	 {
		 IO0CLR = 1U << 31; //LED_ON
		 delay_ms(250);
		 IO0SET = 1U << 31; //LED_OFF
		 delay_ms(250);
	 }
   }
}
void delay_ms(unsigned int j)
{
  unsigned int x, i;
  for(i=0; i<j; i++)
   {
      for(x=0; x<10000; x++);    /* loop to generate 1 milisecond delay with CCLK = 60MHz */
   }
}
