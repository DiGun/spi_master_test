/*
 * spi_m.c
 *
 * Created: 10.07.2017 20:44:43
 * Author : DiGun
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



#include "tm1638.h"
#include "spi.h"

uint8_t L;
uint8_t G;


//#define SPI_REGISTER DDRB
//#define SPI_PORT PORTB

//#define SS PB2   /* SS (RCK) (not necessarily on SS) */
//#define DATA  PB3   /* MOSI (SI) */
//#define CLOCK PB5   /* SCK (SCK) */
//#define OUTEN PB0   /* OE - output enable (active low) */

//#define SPI_EN SPI_PORT&=~(1<<OUTEN)
//#define SPI_DIS SPI_PORT|=(1<<OUTEN)


volatile uint8_t data; //for SPI




/*
ISR (SPI_STC_vect)
{
	setDisplayDigit(SPDR,2,false);
}
*/



int main(void)
{
    /* Replace with your application code */

	L=0;
	G=0;
	DDRD=0xFF;
	PORTD=0;
//	port_setup();
//	init();
	spi_init_master();
	sei();
	_delay_ms(1);
    while (1) 
    {
		
		PORTD=spi_fast_shift(L);
		L++;
		_delay_ms(1000);
//		btn_check();
		
//		setLEDs(L);
//		setDisplayDigit(G,7,false);
/*
		if ((SPSR & (1<<SPIF)) > 0)  // checks to see if the SPI bit is clear
		{
			PORTB&=~(1<<2);
			PORTB|=1<<2;
			
			SPDR=L;               // send the data
		}
*/
				
    }
}

