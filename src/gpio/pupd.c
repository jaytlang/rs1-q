#include <types.h>
#include <gpio.h>

#include "dat.h"

s8int
pinpull(u8int pin, u8int mode)
{
    u8int *ccntl;
    u32int *fcntl;
    u8int offset;
    int i;

    ccntl = (u8int *)GPPUD;

    if(pin > GPMAXPIN){
        return -1;
    }else if(pin > 31){
        fcntl = (u32int *)GPPUDCLK1;
        offset = pin - 32;
    }else{
        fcntl = (u32int *)GPPUDCLK0;
        offset = pin;
    }

    *ccntl = mode;
    for(i = 0; i < 150; i++);
    *fcntl = (1 << offset);
    for(i = 0; i < 150; i++);
    *ccntl = 0;
    *fcntl = 0;
    return 0;
}
