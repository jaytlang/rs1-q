#include "dat.h"

#include <gpio.h>
#include <param.h>
#include <types.h>
#include <uart1.h>

u16int
calcbaudreg(u64int br)
{
	return (SYSFREQ / (8 * br)) - 1;
}

void
u1init(u64int br)
{
	u32int *reg;
	u16int *sreg;

	/* Flip on the UARt and turn off rcv/send */
	reg = (u32int *)AUXEN;
	*reg |= U1ENV;

	reg = (u32int *)U1CNTL;
	*reg = 0x0;

	/* Set to 8 bit mode */
	reg = (u32int *)U1LCR;
	*reg = 0x3;

	/* Disable modem control */
	reg = (u32int *)U1MCR;
	*reg = 0x0;

	/* Disable interrupts */
	reg = (u32int *)U1IER;
	*reg = 0;

	/* Clear FIFOs */
	reg = (u32int *)U1IIR;
	*reg &= 0x6;

	/* Set the baud rate */
	sreg = (u16int *)U1BAUD;
	*sreg = calcbaudreg(br);

	/* Set up the pins and flip on the UART
	 * No room to fail here
	 */
	mapaltfxn(5, 14);
	mapaltfxn(5, 15);

	/* Float pins 14 and 15 */
	pinpull(14, FLOAT);
	pinpull(15, FLOAT);

	/* Done! Enable rcv/tx */
	reg = (u32int *)U1CNTL;
	*reg = 0x3;
}
