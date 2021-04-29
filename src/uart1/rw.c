#include "dat.h"

#include <types.h>

void
print(char *s)
{
	u32int *lsr;
	char *io;

	lsr = (u32int *)U1LSR;
	io = (char *)U1IO;

	for(; *s != '\0'; s++){
		while((*lsr & (0x1 << 5)) == 0)
			;
		*io = *s;
	}
}
