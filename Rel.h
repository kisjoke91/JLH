#ifndef __REL_H__
#define __REL_H__

#define REL_PORT            PORTB
#define REL_DDR             DDRB
#define REL_EN_SPEAKERS     PB0
#define REL_EN_TRANSFORMER  PB1

void REL_init(void);
void REL_switchOn(void);
void REL_switchOff(void);

#endif /* __REL_H__ */
