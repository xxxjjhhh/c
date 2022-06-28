/***
빅폰트를 제작하고
16x2 크기의 LCD에 __ : __ 형태로 시계 표출
D포트는 데이터, B포트는 제어
***/

#include <mega128.h>
#include <stdio.h>
#include <delay.h>

#define lcd_RS_ON  PORTB|=0x01
#define lcd_RS_OFF PORTB&=0b11111100
#define lcd_E_ON   PORTB|=0x04
#define lcd_E_OFF  PORTB&=~0x04
#define lcd_Out    PORTD

//#asm
//    .equ __lcd_port=0x18
//#endasm

//#include <lcd.h>

typedef  unsigned char  BYTE;                      


BYTE flash FONT1[8]={
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011}; 

BYTE flash FONT2[8]={
0b00011111,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011};

BYTE flash FONT3[8]={
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011111};

BYTE flash FONT4[8]={
0b00011111,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011};

BYTE flash FONT5[8]={
0b00011111,
0b00011000,
0b00011000,
0b00011000,
0b00011000,
0b00011000,
0b00011000,
0b00011111};

BYTE flash FONT6[8]={
0b00011111,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00000011,
0b00011111};

BYTE flash FONT7[8]={
0b00011111,
0b00011000,
0b00011000,
0b00011000,
0b00011000,
0b00011000,
0b00011000,
0b00011000};

BYTE flash FONT8[8]={
0b00011111,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011011,
0b00011111}; 


void lcdData(char d){ 
  lcd_RS_ON; 
  lcd_Out=d;
  lcd_E_ON; 
  delay_ms(1); 
  lcd_E_OFF; 
  delay_ms(5); 
}

void lcdCmd(char c){ 
  lcd_RS_OFF; 
  lcd_Out=c; 
  lcd_E_ON; 
  delay_ms(1); 
  lcd_E_OFF; 
  delay_ms(2); 
}


void lcd_init(void){
 
  lcdCmd(0x38); 
  lcdCmd(0x38); 
  lcdCmd(0x38);
  lcdCmd(0x0c);  
  lcdCmd(0x01); 
  delay_ms(10);    
  lcdCmd(0x06);
}    
        
void lcd_write_byte(unsigned char ad, unsigned char da){ 

  lcdCmd(ad);  
  delay_ms(20); 
  lcdData(da); 
  delay_ms(200);  
}
 
void make_custom_font(unsigned char addr, unsigned char flash *font){

    unsigned char cnt, ADDR;
    addr <<= 3;
    ADDR = addr | 0x40;
    for (cnt = 0 ; cnt < 8; ++cnt){       
        lcd_write_byte(ADDR+cnt, font[cnt]);
    }
}

void point();
void min0();
void min1();
void sec0();
void sec1();

void space(){
    lcdCmd(0x82); 
    lcdData(0xA0);
    lcdCmd(0xC2); 
    lcdData(0xA0);
}


void point(){
    lcdCmd(0x82); 
    lcdData(0xA5);
    lcdCmd(0xC2); 
    lcdData(0xA5); 
  
}

void min1(){
    lcdCmd(0x80); 
    lcdData(0x02);
    lcdCmd(0xC0); 
    lcdData(0x03); 
    min0();
              
    lcdCmd(0x80); 
    lcdData(0x01);
    lcdCmd(0xC0); 
    lcdData(0x01); 
    min0();
    
    lcdCmd(0x80); 
    lcdData(0x04);
    lcdCmd(0xC0); 
    lcdData(0x05); 
    min0();
    
    lcdCmd(0x80); 
    lcdData(0x04);
    lcdCmd(0xC0); 
    lcdData(0x06); 
    min0();
    
    lcdCmd(0x80); 
    lcdData(0x03);
    lcdCmd(0xC0); 
    lcdData(0x01); 
     min0();
    
    lcdCmd(0x80); 
    lcdData(0x05);
    lcdCmd(0xC0); 
    lcdData(0x06); 
    min0();
}

void min0(){

    lcdCmd(0x81);
    lcdData(0x02);
    lcdCmd(0xC1); 
    lcdData(0x03); 
    sec1();
              
    lcdCmd(0x81); 
    lcdData(0x01);
    lcdCmd(0xC1); 
    lcdData(0x01); 
    sec1();
    
    lcdCmd(0x81); 
    lcdData(0x04);
    lcdCmd(0xC1); 
    lcdData(0x05); 
    sec1();
    
    lcdCmd(0x81); 
    lcdData(0x04);
    lcdCmd(0xC1); 
    lcdData(0x06); 
    sec1();
    
    lcdCmd(0x81); 
    lcdData(0x03);
    lcdCmd(0xC1); 
    lcdData(0x01); 
    sec1();
    
    lcdCmd(0x81); 
    lcdData(0x05);
    lcdCmd(0xC1); 
    lcdData(0x06); 
    sec1();
    
    lcdCmd(0x81); 
    lcdData(0x05);
    lcdCmd(0xC1); 
    lcdData(0x08); 
    sec1();
    
    lcdCmd(0x81); 
    lcdData(0x04);
    lcdCmd(0xC1); 
    lcdData(0x01); 
    sec1();
    
    lcdCmd(0x81); 
    lcdData(0x08);
    lcdCmd(0xC1); 
    lcdData(0x08); 
    sec1();
     
    lcdCmd(0x81); 
    lcdData(0x08);
    lcdCmd(0xC1); 
    lcdData(0x01); 
    sec1();
}

void sec1(){

    lcdCmd(0x83); 
    lcdData(0x02);
    lcdCmd(0xC3); 
    lcdData(0x03); 
    sec0();
              
    lcdCmd(0x83); 
    lcdData(0x01);
    lcdCmd(0xC3); 
    lcdData(0x01); 
    sec0();
    
    lcdCmd(0x83); 
    lcdData(0x04);
    lcdCmd(0xC3); 
    lcdData(0x05); 
    sec0();
    
    lcdCmd(0x83); 
    lcdData(0x04);
    lcdCmd(0xC3); 
    lcdData(0x06); 
    sec0(); 
    
    lcdCmd(0x83); 
    lcdData(0x03);
    lcdCmd(0xC3); 
    lcdData(0x01); 
    sec0();
    
    lcdCmd(0x83); 
    lcdData(0x05);
    lcdCmd(0xC3); 
    lcdData(0x06); 
    sec0();
}

void sec0(){
          
    lcdCmd(0x84); 
    lcdData(0x02);
    lcdCmd(0xC4); 
    lcdData(0x03); 
    point();
    delay_ms(1000); 
    
              
    lcdCmd(0x84); 
    lcdData(0x01);
    lcdCmd(0xC4); 
    lcdData(0x01); 
    space();
    delay_ms(1000); 
    
    lcdCmd(0x84); 
    lcdData(0x04);
    lcdCmd(0xC4); 
    lcdData(0x05); 
    point();
    delay_ms(1000); 
    
    lcdCmd(0x84); 
    lcdData(0x04);
    lcdCmd(0xC4); 
    lcdData(0x06); 
    space();
    delay_ms(1000); 
    
    lcdCmd(0x84); 
    lcdData(0x03);
    lcdCmd(0xC4); 
    lcdData(0x01); 
    point();
    delay_ms(1000); 
    
    lcdCmd(0x84); 
    lcdData(0x05);
    lcdCmd(0xC4); 
    lcdData(0x06); 
    space();
    delay_ms(1000); 
    
    lcdCmd(0x84); 
    lcdData(0x05);
    lcdCmd(0xC4); 
    lcdData(0x08); 
    point();
    delay_ms(1000); 
    
    lcdCmd(0x84); 
    lcdData(0x04);
    lcdCmd(0xC4); 
    lcdData(0x01); 
    space();
    delay_ms(1000); 
    
    lcdCmd(0x84); 
    lcdData(0x08);
    lcdCmd(0xC4); 
    lcdData(0x08); 
    point();
    delay_ms(1000);  
    
    lcdCmd(0x84); 
    lcdData(0x08);
    lcdCmd(0xC4); 
    lcdData(0x01); 
    space();
    delay_ms(1000); 
    
}


void main(){

    DDRD=0xFF;    DDRB=0xFF;       delay_ms(30);
    PORTB=0x00;   PORTD=0x00;
    lcd_init( );     /* initialize the LCD for 2 lines & 16 columns */  
    make_custom_font(8, FONT8);
    make_custom_font(7, FONT7);
    make_custom_font(6, FONT6);
    make_custom_font(5, FONT5);
    make_custom_font(4, FONT4);
    make_custom_font(3, FONT3);  
    make_custom_font(2, FONT2);
    make_custom_font(1, FONT1); 
    
    
    while(1){     
        min1();        
    }
}
