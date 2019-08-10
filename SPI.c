#include "SPI.h"
#include <avr/io.h>

void SPI_init() {

    SPI_DDR |= (1 << SPI_PIN_SCK) |
               (1 << SPI_PIN_MOSI) |
               (1 << SPI_PIN_CS);       // SCK, MOSI and SS as outputs

    SPI_PORT |= (1 << SPI_PIN_CS);      // Deselect potentiometer chip

    SPCR |= (1 << MSTR);                // Set as Master
    SPCR |= (1 << SPR0) | (0 << SPR1);  // Divided clock by 128
    SPCR |= (1 << SPE);                 // Enable SPI
}

void SPI_write(unsigned char data) {

    SPDR = data;                        // Send the data
    while(!(SPSR & (1 << SPIF)));
}
