#include <lpc214x.h>
#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)
void delay_ms(unsigned int j);
void elevator_run(void);
int main()
{
IO0DIR |= 1U << 31 | 0XFF << 16;
IO1DIR |= 1 << 24; 
LED_ON; 
elevator_run( );
while(1);
}
void elevator_run(void)
{
 int i,val;
unsigned int counter;
IO1CLR = 1 << 24; 
IO0CLR = 0X000F0000;
do{

IO0CLR = 0X00F00000;IO0SET = 0X00F00000; 

do{
 counter = (IO1PIN >> 16) & 0X0000000F ; 
}while(counter == 0x0F);
if(counter == 0x0e) val=3; 
else if(counter == 0x0d) val=6; 
else if(counter == 0x0b) val=8; 
else if(counter == 0x07) val=10;

for(i=0 ; i<val ; i++) 
{
IO0CLR = 0X000F0000;IO0SET = i << 16;
delay_ms(250);
}

for(i=val-1;i>=0;i--)
{
IO0CLR = 0X000F0000;IO0SET = i << 16;
delay_ms(250);
}
} while(1);
}
