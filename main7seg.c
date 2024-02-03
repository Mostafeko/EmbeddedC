/*
 * main7seg.c
 *
 *  Created on: Feb 3, 2024
 *      Author: Compu Fast
 */


#include <stdint.h>
#include <util/delay.h>

#define GET_BIT(Reg,Bit_Num) ((Reg>>Bit_Num)&1)
#define SET_BIT(Reg,Bit_Num) Reg|=(1<<Bit_Num)
#define CLR_BIT(Reg,Bit_Num) Reg&=~(1<<Bit_Num)
#define TOG_BIT(Reg,Bit_Num) Reg^=(1<<Bit_Num)

#define DDRA (*(volatile unsigned char*)0x3A)
#define PORTA (*(volatile unsigned char*)0x3B)

#define DDRC (*(volatile unsigned char*)0x34)
#define PORTC (*(volatile unsigned char*)0x35)
#define PINC (*(volatile unsigned char*)0x33)

#define DDRD (*(volatile unsigned char*)0x31)
#define PORTD (*(volatile unsigned char*)0x32)

#define segment_Port PORTD

void segment_Display(char num){
	char segmentArr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
	segment_Port=segmentArr[num];
}

void main(void){
		DDRC=0x3F;
		PORTC=255;
		DDRD=255;
		while(1){

			if(GET_BIT(PINC,0)==0){ // if Push button is pressed in c0
					int i;
					for(i = 0; i<10; i++){
						segment_Display(i);
						_delay_ms(300);
						if(i == 9){
							i=0;
						}
						if(GET_BIT(PINC,1)==0){
							break;
						}
					}
				}
			if(GET_BIT(PINC,2)==0){
									segment_Display(0);
								}
		}
}

