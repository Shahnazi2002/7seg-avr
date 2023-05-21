/*******************************************************
Project : Display numbers on a 7-segment common cathode
Date    : 05/21/2023
Author  : Mohammad Shahnazi 


Chip type      : ATmega32
Program type   : Application
AVR Core Clock : 8.000000 MHz
Memory model   : Small
Data Stack size: 512
*******************************************************/

#include <mega32.h>
#include <delay.h>

int i;

/*******************************************************
Digit    g f e d c b a    HEX
-----    -------------    ---
0        0 1 1 1 1 1 1    3F
1        0 0 0 0 1 1 0    06
2        1 0 1 1 0 1 1    5B
3        1 0 1 1 0 1 1    4F
4        1 1 0 0 1 1 0    66
5        1 1 0 1 1 0 1    6D
6        1 1 1 1 1 0 1    7D
7        0 0 0 0 1 1 1    07
8        1 1 1 1 1 1 1    7F
9        1 1 0 1 1 1 1    6F
*******************************************************/
int digits[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void main(void)
{ 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0); 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0); 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0); 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0); 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

while (1)
      {
      for (i = 0; i < 10; i++) {
      PORTC = digits[i];
      delay_ms(500);
      }
      }
}