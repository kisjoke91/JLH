#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "Pot.h"
#include "SPI.h"
#include "Rel.h"

unsigned char volume = DEFAULT_VOLUME;

void POT_init(void) {

    POT_DDR &=~ (1 << POT_PIN_BUTTON);
    POT_DDR &=~ (1 << POT_PIN_B);
    POT_DDR &=~ (1 << POT_PIN_A);

    POT_PORT |= (1 << POT_PIN_BUTTON)|(1 << POT_PIN_B)|(1 << POT_PIN_A);
}

void POT_set(char channel, unsigned char value) {

    SPI_PORT &= ~(1 << SPI_PIN_CS);             // Select potentiometer chip
    SPI_write(POT_COMMAND_WRITE | channel);     // Send write command
    SPI_write(value);                           // Set new value
    SPI_PORT |= (1 << SPI_PIN_CS);              // Deselect potentiometer chip
}

void POT_handlePowerButton(void) {

    if (!(POT_PIN & (1 << POT_PIN_BUTTON))) {

        _delay_ms(200);
        if (!(REL_PORT & (1 << REL_EN_TRANSFORMER))) REL_switchOn();
        else REL_switchOff();

        while (!(POT_PIN & (1 << POT_PIN_BUTTON)));
    }
}

unsigned char POT_getVolume(void) {

    return volume;
}

void POT_decreaseVolume(void) {

    if (volume >= VOLUME_STEPS) {

        volume -= VOLUME_STEPS;
        POT_set(POT_CH_BOTH, volume);
    }
}

void POT_increaseVolume(void) {

    if (volume <= MAX_VOLUME - VOLUME_STEPS) {

        volume += 5;
        POT_set(POT_CH_BOTH, volume);
    }
}
