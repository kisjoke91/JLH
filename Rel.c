#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Rel.h"
#include "Pot.h"
#include "SPI.h"


void REL_init(void) {

    REL_DDR |= (1 << REL_EN_SPEAKERS) | (1 << REL_EN_TRANSFORMER);
    REL_PORT &= ~((1 << REL_EN_SPEAKERS) | (1 << REL_EN_TRANSFORMER));

    POT_init();
    SPI_init();

    REL_switchOff();
}

void REL_switchOn(void) {

    POT_set(POT_CH_BOTH, 0);
    REL_PORT |= (1 << REL_EN_TRANSFORMER);
    _delay_ms(2000);
    REL_PORT |= (1 << REL_EN_SPEAKERS);
    POT_set(POT_CH_BOTH, POT_getVolume());
}

void REL_switchOff(void) {

    POT_set(POT_CH_BOTH, 0);
    REL_PORT &= ~(1 << REL_EN_SPEAKERS);
    _delay_ms(300);
    REL_PORT &= ~(1 << REL_EN_TRANSFORMER);
}
