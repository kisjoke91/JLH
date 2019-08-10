#ifndef __POT_H__
#define __POT_H__

#define DEFAULT_VOLUME      255
#define MAX_VOLUME          255
#define VOLUME_STEPS        5

#define POT_CH_NONE         0x00
#define POT_CH_LEFT         0x01   // Potentiometer 0
#define POT_CH_RIGHT        0x02   // Potentiometer 1
#define POT_CH_BOTH         0x03
#define POT_COMMAND_WRITE   0x10

#define POT_PORT            PORTD
#define POT_DDR             DDRD
#define POT_PIN             PIND
#define POT_PIN_A           3
#define POT_PIN_B           2
#define POT_PIN_BUTTON      1

void POT_init(void);
void POT_set(char channel, unsigned char value);
void POT_handlePowerButton(void);
unsigned char POT_getVolume(void);
void POT_increaseVolume(void);
void POT_decreaseVolume(void);
#endif /* __POT_H__ */
