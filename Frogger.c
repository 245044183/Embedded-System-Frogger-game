//
//  Frogger.c
//  Frogger
//
//  Created by Chen on 4/23/19.
//  Copyright � 2019 Chen. All rights reserved.
//
#include "LPC17xx.H"
#include "GLCD.h"
#include <stdlib.h>
#include "uart.h"
#include "system_LPC17xx.h"
#include "LPC17xx.H"
#include "GLCD.h"
#include "GLCD_UTILS.h"
#include <math.h>
#include <stdlib.h>
extern volatile uint32_t UART0_Count;
extern volatile uint8_t UART0_Buffer[BUFSIZE];
void TIMER0_IRQHandler(void) {
		LPC_TIM0->IR |= 1; //Clear interrupt source

}
void drawRect(int x1, int x2, int y1, int y2,unsigned short color){
    
    int x=0;
    int y=0;
    GLCD_SetTextColor(color);
    for(x=x1;x<x2;x++){
        for (y=y1;y<y2;y++){
            GLCD_PutPixel(x,y);
        }
        
    }
    
}
void drawhome(char top[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top[i] == '0'){
			GLCD_SetTextColor(LightGrey);
			for (j=0; j<20; j++){
				for (k=0; k<24; k++){
					GLCD_PutPixel(j+(i*20),k);
				}
			}				
		}
		if (top[i] == '1'){
			GLCD_SetTextColor(DarkGrey);
			for (j=0; j<20; j++){
				for (k=0; k<24; k++){
					GLCD_PutPixel(j+(i*20),k);
				}
			}
		}
	}
}

void drawtop2(char top2[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top2[i] == '2'){
			GLCD_SetTextColor(Brown);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+24);
				}
			}				
		}
		if (top2[i] == '3'){
			GLCD_SetTextColor(Blue);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+24);
				}
			}
		}
	}
}

void drawtop3(char top3[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top3[i] == '4'){
			GLCD_SetTextColor(Pink);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+42);
				}
			}				
		}
		if (top3[i] == '3'){
			GLCD_SetTextColor(Blue);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+42);
				}
			}
		}
	}
}

void drawtop4(char top4[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top4[i] == '2'){
			GLCD_SetTextColor(Brown);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+60);
				}
			}				
		}
		if (top4[i] == '3'){
			GLCD_SetTextColor(Blue);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+60);
				}
			}
		}
	}
}

void drawtop5(char top5[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top5[i] == '2'){
			GLCD_SetTextColor(Brown);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+78);
				}
			}				
		}
		if (top5[i] == '3'){
			GLCD_SetTextColor(Blue);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+78);
				}
			}
		}
	}
}

void drawtop6(char top6[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top6[i] == '4'){
			GLCD_SetTextColor(Pink);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+96);
				}
			}				
		}
		if (top6[i] == '3'){
			GLCD_SetTextColor(Blue);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+96);
				}
			}
		}
	}
}
void drawtop7(){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
			GLCD_SetTextColor(Purple);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+114);
				}
			}				
		}
	}
void drawtop8(char top8[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top8[i] == '8'){
			GLCD_SetTextColor(Black);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+132);
				}
			}				
		}
		if (top8[i] == '6'){
			GLCD_SetTextColor(Red);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+132);
				}
			}
		}
	}
}
	void drawtop9(char top9[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top9[i] == '8'){
			GLCD_SetTextColor(Black);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+150);
				}
			}				
		}
		if (top9[i] == '7'){
			GLCD_SetTextColor(Yellow);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+150);
				}
			}
		}
	}
}
	void drawtop10(char top10[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top10[i] == '8'){
			GLCD_SetTextColor(Black);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+168);
				}
			}				
		}
		if (top10[i] == '6'){
			GLCD_SetTextColor(Red);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+168);
				}
			}
		}
	}
}
	void drawtop11(char top11[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top11[i] == '8'){
			GLCD_SetTextColor(Black);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+186);
				}
			}				
		}
		if (top11[i] == '7'){
			GLCD_SetTextColor(Yellow);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+186);
				}
			}
		}
	}
}
	void drawtop12(char top12[]){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
		if (top12[i] == '8'){
			GLCD_SetTextColor(Black);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+204);
				}
			}				
		}
		if (top12[i] == '6'){
			GLCD_SetTextColor(Yellow);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+204);
				}
			}
		}
	}
}

void drawtop13(){
	int i;
	int j;
	int k;
	for (i=0; i<13; i++){
			GLCD_SetTextColor(Purple);
			for (j=0; j<20; j++){
				for (k=0; k<18; k++){
					GLCD_PutPixel(j+(i*20),k+222);
				}
			}				
		}
	}


void drawFrog(int frogx, int frogy, int width, unsigned short color){
	int i;
	int j;
	GLCD_SetTextColor(color);
	for (i=frogx-(width/2);i<frogx+(width/2);i++){
				for (j=frogy-(width/2);j<frogy+(width/2);j++){
					if(sqrt(((abs(frogx-i))^2)+((abs(frogy-j))^2))<3){
						GLCD_PutPixel(i,j);
					}
				}
		}
}

int main() {
			int frogxposition;
			int pause=0;
			int	tmp2;
			int tmp3;
			int tmp4;
			int tmp5;
			int tmp6;
			int tmp8;
			int tmp9;
			int tmp10;
			int tmp11;
			int tmp12;
			int life=4;
			int arrive=0;
//	int mask_val_up = 0x100;
//	int mask_val_left = 0x1000;
//	int mask_val_right = 0x02000;
//	int mask_val_down = 0x200000;
//	int on_val = 0x00000000;
		int mask_val_select= 0x2000000;
//		int mask_val_right = 0x4000000;
//		int mask_val_down = 0x8000000;
//		int mask_val_up= 0x10000000;
//		int mask_val_left= 0x20000000;
	int on_val = 0;
	int frogx = 110;
	int frogy = 231;
	int width = 10;
	char top[13] = {'0', '1', '1', '0', '1', '1', '0', '1', '1', '0' ,'1' , '1', '0'};//home
	char top2[13] = {'2', '2', '2', '3', '3', '3', '2', '2', '2', '3' ,'3' , '3', '2'};//3 is danger
	char top3[13] = {'3', '3', '4', '4', '3', '3', '4', '4', '3', '3' ,'4' , '4', '3'};//3 is danger
	char top4[13] = {'3', '3', '2', '2', '2', '3', '3', '3', '2', '2' ,'2' , '3', '3'};//3 is danger
	char top5[13] = {'3', '2', '2', '2', '3', '3', '3', '2', '2', '2' ,'3' , '3', '3'};//3 is danger
	char top6[13] = {'3', '4', '4', '3', '3', '4', '4', '3', '3', '4' ,'4' , '3', '3'};//3 is danger
	char top8[13] = {'8', '8', '6', '8', '8', '8', '6', '8', '8', '8' ,'6' , '8', '8'};//8 is not danger
	char top9[13] = {'8', '7', '7', '7', '8', '8', '8', '8', '7', '7' ,'7' , '8', '8'};//8 is not danger
	char top10[13] = {'6', '8', '8', '8', '6', '8', '8', '8', '6', '8' ,'8' , '6', '8'};//8 is not danger
	char top11[13] = {'7', '7', '7', '8', '8', '8', '8', '7', '7', '7' ,'8' , '8', '8'};//8 is not danger
  char top12[13] = {'8', '6', '8', '8', '8', '6', '8', '8', '8', '6' ,'8' , '8', '8'};//8 is not danger
	LPC_TIM0->MR0 = 24000000; //Set up 1s match value
	  LPC_TIM0->MCR |= 3;       //bit0 for interrupt, bit1 for reset
		NVIC_EnableIRQ(TIMER0_IRQn);
		LPC_TIM0->TCR |= 2;       //bit1 is reset bit
		LPC_TIM0->TCR &= ~2;      //clear reset
	  LPC_TIM0->TCR |= 1;			  //start timer (bit 0 is start bit)
		//UART init for part C
		UARTInit(0, 57600);
		LPC_GPIO2->FIODIR = 0x00000000; 
		GLCD_Init();               //Initializes the LCD display
		GLCD_Clear(Black);         //Clear display and set background color to black
  //drawSquare(frogx,frogy,width,Red);
  while(1){
		if (pause==1){
		GLCD_DisplayString(5,5,"Pause");
		}
	while(pause==0) {                 
	
			int k;
			if ( UART0_Count != 0 ) {
						char c = UART0_Buffer[0];						
						UARTSend( 0, (uint8_t *)UART0_Buffer, UART0_Count);
						UART0_Count = 0;
				if (c=='w') frogy+=18;
				if (c=='s') frogy-=18;
				if (c=='d') frogx-=20;
				if (c=='a') frogx+=20;
			}
//			if ((LPC_GPIO1->FIOPIN & mask_val_up) == on_val) {
//					frogy+=18;
//			}
//			if ((LPC_GPIO1->FIOPIN & mask_val_left) == on_val) {
//					frogx+=20;
//					
//			}
//			if ((LPC_GPIO1->FIOPIN & mask_val_right) == on_val) {

//					frogx-=20;
//			}
//			if ((LPC_GPIO1->FIOPIN & mask_val_down) == on_val) {
//					frogy-=18;
//			}
				
//			above is the pin for school board
			
			frogxposition=(frogx-10)/20;//xposition of the frog
			if ((frogy>=0&&frogy<=24)){ // top 0 collision and ride (count from top to bottom)

				if (top2[frogxposition]=='1'){
						life--;
						frogx=130;
						frogy=231;
					}
					else if(top2[frogxposition]=='0'){
					arrive++;
					} 
			}
			if ((frogy>=24&&frogy<=42)){ // top 1 collision and ride (count from top to bottom)

				if (top2[frogxposition]=='3'){
						life--;
						frogx=130;
						frogy=231;
					}
					else if((frogy>=24&&frogy<=42)||(frogy>=96&&frogy<=116)||(frogy>=60&&frogy<=78)){
					frogx=frogx-20;
					}
					else if ((frogy>=42&&frogy<=60)||(frogy>=78&&frogy<=96)){
					frogx=frogx+20;
					} 
			}
			else if((frogy>=42&&frogy<=60)){ //top 2 collision and ride

				if (top3[frogxposition]=='3'){
						life--;
						frogx=130;
						frogy=231;
					}
					else if((frogy>=24&&frogy<=42)||(frogy>=96&&frogy<=116)||(frogy>=60&&frogy<=78)){
						frogx=frogx-20;
					}
					else if ((frogy>=42&&frogy<=60)||(frogy>=78&&frogy<=96)){
						frogx=frogx+20;
					} 
			}
			else if((frogy>=60&&frogy<=78)){ //top 3 collision and ride
			
				if (top4[frogxposition]=='3'){
						life--;
						frogx=130;
						frogy=231;
					}
					else if((frogy>=24&&frogy<=42)||(frogy>=96&&frogy<=116)||(frogy>=60&&frogy<=78)){
						frogx=frogx-20;
					}
					else if ((frogy>=42&&frogy<=60)||(frogy>=78&&frogy<=96)){
						frogx=frogx+20;
					} 
			}
			else if((frogy>=78&&frogy<=96)){ //top 4 collision and ride

				if (top5[frogxposition]=='3'){
						life--;
						frogx=130;
						frogy=231;
					}
					else if((frogy>=24&&frogy<=42)||(frogy>=96&&frogy<=116)||(frogy>=60&&frogy<=78)){
						frogx=frogx-20;
					}
					else if ((frogy>=42&&frogy<=60)||(frogy>=78&&frogy<=96)){
						frogx=frogx+20;
					} 
			}
			else if((frogy>=96&&frogy<=114)){ //top 5 collision and ride

				if (top6[frogxposition]=='3'){
						life--;
						frogx=130;
						frogy=231;
					}
					else if((frogy>=24&&frogy<=42)||(frogy>=96&&frogy<=116)||(frogy>=60&&frogy<=78)){
						frogx=frogx-20;
					}
					else if ((frogy>=42&&frogy<=60)||(frogy>=78&&frogy<=96)){
						frogx=frogx+20;
					} 
			}

					
			
			
			if (frogy>=132&&frogy<=150){// bottom 1 collision 
				if (top8[frogxposition]!='5'){
					life--;
					frogx=130;
					frogy=231;
				} 
					
				 
			}
			else if (frogy>=150&&frogy<=168){ // bottom 2 collision 
				if (top9[frogxposition]!='5'){
					life--;
					frogx=130;
					frogy=231;
				} 
					
				 
			}
			else if (frogy>=168&&frogy<=186){ // bottom 3 collision 
				if (top10[frogxposition]!='5'){
					life--;
					frogx=130;
					frogy=231;
				} 
					
				 
			}
			else if (frogy>=186&&frogy<=204){ // bottom 4 collision 
				if (top11[frogxposition]!='5'){
					life--;
					frogx=130;
					frogy=231;
				} 
					
				 
			}
			else if (frogy>=204&&frogy<=222){ // bottom 5 collision 
				if (top12[frogxposition]!='5'){
					life--;
					frogx=130;
					frogy=231;
				} 
					
				 
			}

		
		
			drawhome(top);
			drawtop2(top2);
			drawtop3(top3);
			drawtop4(top4);
			drawtop5(top5);
			drawtop6(top6);
			drawtop7();
			drawtop8(top8);
			drawtop9(top9);
			drawtop10(top10);
			drawtop11(top11);
			drawtop12(top12);
			drawtop13();
			drawFrog(frogx,frogy,width,Green);


		
			
			tmp2 = top2[0];
			tmp3= top3[12];
			tmp4 = top4[0];
			tmp5= top5[12];
			tmp6 = top6[0];
			tmp8= top8[12];
			tmp9 = top9[0];
			tmp10= top10[12];
			tmp11 = top11[0];
			tmp12= top12[12];
			for (k = 0; k < 13; k++){
				top2[k] = top2[k+1];
				top4[k] = top4[k+1];
				top6[k] = top6[k+1];
				top9[k] = top9[k+1];
				top11[k] = top11[k+1];
			}
	     for (k = 13; k > 0; k--){
				top3[k] = top3[k-1];
				top5[k] = top5[k-1];
				top8[k] = top8[k-1];
				top10[k] = top10[k-1];
				top12[k] = top12[k-1];
			}
			top2[12] = tmp2;
			top3[0] = tmp3;
			top4[12] =tmp4;
			top5[0] = tmp5;
			top6[12] = tmp6;
			top8[0] = tmp8;
			top9[12] = tmp9;
			top10[0] = tmp10;
			top11[12] = tmp11;
			top12[0] = tmp12;


			for (k=0;k<12000000;k++);
			
//			if ((LPC_GPIO1->FIOPIN & mask_val_up) == on_val) {
//					frogy+=18;
//			}
//			if ((LPC_GPIO1->FIOPIN & mask_val_left) == on_val) {
//					frogx+=20;
//					
//			}
//			if ((LPC_GPIO1->FIOPIN & mask_val_right) == on_val) {

//					frogx-=20;
//			}
//			if ((LPC_GPIO1->FIOPIN & mask_val_down) == on_val) {
//					frogy-=18;
//			}
			if ((LPC_GPIO1->FIOPIN & mask_val_select) == on_val) {
				if (pause==1) pause=0;
				if (pause==0)	pause=1;
				
			}


							if (frogy>=0&&frogy<=24){
				if (top[frogxposition]=='0'){
					arrive++;
					frogx=130;
					frogy=231;
				}
				else 
					life=life-1;
				  frogx = 130;
					frogy = 231;
			}
			else if (arrive==5){
				while (1){
					GLCD_DisplayString(5,5,"You Win");
				}
			
				//while 1 loop print you win
			}
		
			
			if (frogxposition<=0)frogxposition=0;
			if (life==4){
				GLCD_DisplayString(8,18,"4");
			}
			if (life==3){
				GLCD_DisplayString(8,18,"3");
			}
			if (life==2){
				GLCD_DisplayString(8,18,"2");
			}
			if (life==1){
				GLCD_DisplayString(8,18,"1");
			}
			else if (life==0){
				while (1){
					GLCD_DisplayString(5,5,"GAME OVER");
				}
				//while 1 loop print gmae over;
			}

	}
	pause=0;
		if ((LPC_GPIO1->FIOPIN & mask_val_select) == on_val) {
					pause=1;
			}
}

}
