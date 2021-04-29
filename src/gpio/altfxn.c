#include "dat.h"

#include <gpio.h>
#include <types.h>

s8int
mapaltfxn(u8int fxn, u8int pin)
{
	u32int *reg, v;
	u8int regno, offset;

	if(fxn > GPMAXF || pin > GPMAXPIN){ return -1; }

	regno = pin / 10;
	offset = (pin % 10) * 3;
	switch(regno){
	case 0: reg = (u32int *)GPFSEL0; break;
	case 1: reg = (u32int *)GPFSEL1; break;
	case 2: reg = (u32int *)GPFSEL2; break;
	case 3: reg = (u32int *)GPFSEL3; break;
	case 4: reg = (u32int *)GPFSEL4; break;
	case 5: reg = (u32int *)GPFSEL5; break;
	}

	v = *reg & ~(GPPININ << offset);
	switch(fxn){
	case 0: v |= (GPPINF0 << offset); break;
	case 1: v |= (GPPINF1 << offset); break;
	case 2: v |= (GPPINF2 << offset); break;
	case 3: v |= (GPPINF3 << offset); break;
	case 4: v |= (GPPINF4 << offset); break;
	case 5: v |= (GPPINF5 << offset); break;
	}
	*reg = v;
	return 0;
}
