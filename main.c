#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "SPI.h"
#include "Rel.h"
#include "Pot.h"

unsigned char vol = MAX_VOLUME;

uint8_t read_gray_code_from_encoder(void ) {
    uint8_t val=0;

    if(!bit_is_clear(PIND, PD2)) val |= (1<<0);
    if(!bit_is_clear(PIND, PD3)) val |= (1<<1);

    return val;
}

int main(void)
{
    REL_init();

    uint8_t val = 0;
    uint8_t val_tmp = 0;

    while(1) {

        POT_handlePowerButton();

        val_tmp = read_gray_code_from_encoder();

	    if(val != val_tmp) {

            if((val==3 && val_tmp==1) || (val==0 && val_tmp==2)) {

                POT_increaseVolume();
            }

		    else if((val==2 && val_tmp==0) || (val==1 && val_tmp==3)) {
				POT_decreaseVolume();
		    }

		    val = val_tmp;
	   }
    }
}
