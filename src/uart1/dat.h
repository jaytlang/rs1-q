#ifndef INC_UART1_DAT
#define INC_UART1_DAT

#include <memlayout.h>
#include <types.h>

#define AUXBASE MMIOBASE + 0x215000

#define AUXEN AUXBASE + 0x4
#define U1ENV 0x1

#define U1IO   AUXBASE + 0x40
#define U1IER  AUXBASE + 0x44
#define U1IIR  AUXBASE + 0x48
#define U1LCR  AUXBASE + 0x4c
#define U1MCR  AUXBASE + 0x50
#define U1LSR  AUXBASE + 0x54
#define U1MSR  AUXBASE + 0x58
#define U1CNTL AUXBASE + 0x60
#define U1BAUD AUXBASE + 0x64

#endif /* INC_UART1_DAT */
