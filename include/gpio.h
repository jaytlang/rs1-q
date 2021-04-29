#ifndef INC_RS1_GPIO
#define INC_RS1_GPIO

#include <types.h>

s8int mapaltfxn(u8int fxn, u8int pin);
s8int pinpull(u8int pin, u8int mode);

#define FLOAT    0
#define PULLDOWN 1
#define PULLUP   2

#endif /* INC_RS1_GPIO */
