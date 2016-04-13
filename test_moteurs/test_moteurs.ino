/*
 Test du pilotage des moteurs
  
*/
 
#include "LCD4884.h"
 
#include <Wire.h>
//#define MOTORSHIELDaddr 0x0f
#define SETPWMAB 0x82
#define SETFREQ 0x84
#define CHANGEADDR 0x83
#define CHANNELSET 0xaa
#define MOTOR1 0xa1
#define MOTOR2 0xa5
#define SAVEADDR 'S'
#define NOTSAVEADDR 'N'

static unsigned char MOTORSHIELDaddr = 0x0f; //0x28;
 
int counter = 0;
char string[10];
 
void speedAB(unsigned char spda , unsigned char spdb)
{
	Wire.beginTransmission(MOTORSHIELDaddr); // transmit to device MOTORSHIELDaddr
	Wire.write(SETPWMAB); //set pwm header
	Wire.write(spda); // send pwma
	Wire.write(spdb); // send pwmb
	Wire.endTransmission(); // stop transmitting
}

void fre_pre(unsigned char pres)
{
	Wire.beginTransmission(MOTORSHIELDaddr); // transmit to device MOTORSHIELDaddr
	Wire.write(SETFREQ); // set frequence header
	Wire.write(pres); // send prescale
	Wire.write(0); // need to send this byte as the third byte(no meaning)
	Wire.endTransmission(); //
}

void change_adr(unsigned char new_adr, unsigned char save_or_not)
{
	Wire.beginTransmission(MOTORSHIELDaddr); // transmit to device MOTORSHIELDaddr
	Wire.write(CHANGEADDR); // change address header
	Wire.write(new_adr); // send new address
	Wire.write(save_or_not); // save the new address or not
	Wire.endTransmission(); //
	delayMicroseconds(100); //this command needs at least 6 us
}

void channel(unsigned char i4) //0b 0000 I4 I3 I2 I1
{
	// delayMicroseconds(4);
	Wire.beginTransmission(MOTORSHIELDaddr); // transmit to device MOTORSHIELDaddr
	Wire.write(CHANNELSET); // channel control header
	Wire.write(i4); // send channel control information
	Wire.write(0); // need to send this byte as the third byte(no meaning)
	Wire.endTransmission(); //
}

void motorAndspd( unsigned char motor_s,unsigned char Mstatus, unsigned char spd)
{
	Wire.beginTransmission(MOTORSHIELDaddr); // transmit to device MOTORSHIELDaddr
	Wire.write(motor_s); // motor select information
	Wire.write(Mstatus); // motor satus information
	Wire.write(spd); // motor speed information
	Wire.endTransmission(); // 
}

void setup()
{
 
  lcd.LCD_init();
  lcd.LCD_clear();
 
  //menu initialization
  init_MENU();
}
 
void init_MENU(void)
{
	lcd.LCD_clear();
	lcd.LCD_write_string(0, 0, " test moteurs ", MENU_HIGHLIGHT );
	
	lcd.LCD_write_string(10, 2, "Mot A  Mot B", MENU_NORMAL);

	Wire.begin(); // join i2c bus (address optional for master)
	delayMicroseconds(10); //wait for motor driver to initialization  
}
 
void loop()
{

	lcd.LCD_write_string(10, 3, "+255   +030", MENU_NORMAL);
	motorAndspd(MOTOR1, 0b01, 225);
	motorAndspd(MOTOR2, 0b01, 30);
	
	delay(2000);
	
	lcd.LCD_write_string(10, 3, "-030   +255", MENU_NORMAL);
	motorAndspd(MOTOR1, 0b10, 30);
	motorAndspd(MOTOR2, 0b10, 225);
	
	delay(2000);
}