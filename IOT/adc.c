#include <lpc214x.h>
#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)
#define PLOCK 0x00000400
void delay_ms(unsigned int j);
void SystemInit(void);
void runDCMotor(int direction,int dutycycle);
unsigned int adc(int no,int ch);
int main()
{
int dig_val;
IO0DIR |= 1U << 31 | 0x00FF0000 | 1U << 30; // to set P0.16 to P0.23 as o/ps
LED_ON; delay_ms(500);LED_OFF; 
SystemInit( );
do{
dig_val = adc(1,2) / 10;
if(dig_val > 100) dig_val =100;
runDCMotor(2,dig_val); 
}
while(1);
}
void runDCMotor(int direction,int dutycycle)
{
 IO0DIR |= 1U << 28; 
 PINSEL0 |= 2 << 18; 
 if (direction == 1)
IO0SET = 1 << 28; 
else
 IO0CLR = 1 << 28; 
 
 PWMPCR = (1 << 14); 
 PWMMR0 = 1000; 
 PWMMR6 = (1000U*dutycycle)/100;
 PWMTCR = 0x00000009; 
 PWMLER = 0X70; 
}

unsigned int adc(int no,int ch)
{

unsigned int val;
PINSEL0 |= 0x0F300000;
 switch (no) 
 {
 case 0: AD0CR=0x00200600|(1<<ch); 
 AD0CR|=(1<<24); 
 while((AD0GDR& (1U<<31))==0);
 val=AD0GDR;
 break;
 case 1: AD1CR=0x00200600|(1<<ch); 
 AD1CR|=(1<<24);
 while((AD1GDR&(1U<<31))==0);
 val=AD1GDR;
 break;
 }
 val=(val >> 6) & 0x03FF; 
 return val;
}
void SystemInit(void)
{
 PLL0CON = 0x01; 
 PLL0CFG = 0x24; 
 PLL0FEED = 0xAA; 
 PLL0FEED = 0x55; 
 while( !( PLL0STAT & PLOCK ))
 { ; }
 PLL0CON = 0x03;
 PLL0FEED = 0xAA; 
 PLL0FEED = 0x55;
 VPBDIV = 0x01; 
}
void delay_ms(unsigned int j)
{
 unsigned int x,i;
 for(i=0;i<j;i++)
 {
 for(x=0; x<10000; x++); 
 }
}
