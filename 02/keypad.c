/*******************************************************
Project : Display pressed key on a keypad 
Date    : 05/26/2023
Author  : Mohammad Shahnazi 
Comments: https://github.com/Shahnazi2002

Chip type               : ATmega32
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>

int digits[13] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0b01000000, 0, 0};

int keypad(void){
int r;
for (r=0;r<4;r++){
if (r==0) {
PORTC.0=0;
PORTC.1=1;
PORTC.2=1;
PORTC.3=1;
if (PINC.4==0) {return 1;}
if (PINC.5==0) {return 2;}
if (PINC.6==0) {return 3;}
}
if (r==1) {
PORTC.0=1;
PORTC.1=0;
PORTC.2=1;
PORTC.3=1;
if (PINC.4==0) {return 4;}
if (PINC.5==0) {return 5;}
if (PINC.6==0) {return 6;}
}
if (r==2) {
PORTC.0=1;
PORTC.1=1;
PORTC.2=0;
PORTC.3=1;
if (PINC.4==0) {return 7;}
if (PINC.5==0) {return 8;}
if (PINC.6==0) {return 9;}
}
if (r==3) {
PORTC.0=1;
PORTC.1=1;
PORTC.2=1;
PORTC.3=0;
if (PINC.4==0) {return 10;}
if (PINC.5==0) {return 0;}
if (PINC.6==0) {return 11;}
}
}
return 12;
}

void main(void)
{ 
DDRC=(0<<DDC7)|(0<<DDC6)|(0<<DDC5)|(0<<DDC4)|(1<<DDC3)|(1<<DDC2)|(1<<DDC1)|(1<<DDC0);
PORTC=(1<<PORTC7)|(1<<PORTC6)|(1<<PORTC5)|(1<<PORTC4)|(1<<PORTC3)|(1<<PORTC2)|(1<<PORTC1)|(1<<PORTC0);
DDRD=(1<<DDD7)|(1<<DDD6)|(1<<DDD5)|(1<<DDD4)|(1<<DDD3)|(1<<DDD2)|(1<<DDD1)|(1<<DDD0);
PORTD=(0<<PORTD7)|(0<<PORTD6)|(0<<PORTD5)|(0<<PORTD4)|(0<<PORTD3)|(0<<PORTD2)|(0<<PORTD1)|(0<<PORTD0);

while (1)
{
int number = keypad();
if (number!=12) {PORTD=digits[number];}
}}
