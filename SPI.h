#ifndef __SPI_H__
#define __SPI_H__

#define SPI_PORT            PORTB
#define SPI_DDR             DDRB
#define SPI_PIN_SCK         PB5
#define SPI_PIN_MOSI        PB3
#define SPI_PIN_CS          PB2

void SPI_init();
void SPI_write(unsigned char data);

#endif /* __SPI_H__ */
