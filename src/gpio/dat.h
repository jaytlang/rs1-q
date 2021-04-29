#ifndef INC_GPIO_DAT
#define INC_GPIO_DAT

#include <memlayout.h>

#define GPBASE MMIOBASE + 0x200000

#define GPMAXPIN 53
#define GPMAXF   5

/* GPFSELx: define operation of pins
 * 3 bits per pin -> covers up to 53
 */
#define GPFSEL0 GPBASE + 0x0
#define GPFSEL1 GPBASE + 0x4
#define GPFSEL2 GPBASE + 0x8
#define GPFSEL3 GPBASE + 0xc
#define GPFSEL4 GPBASE + 0x10
#define GPFSEL5 GPBASE + 0x14

/* Values for the GPFSELx bits for
 * a given pin
 */
#define GPPININ  0x0
#define GPPINOUT 0x1
#define GPPINF5  0x2
#define GPPINF4  0x3
#define GPPINF0  0x4
#define GPPINF1  0x5
#define GPPINF2  0x6
#define GPPINF3  0x7

/* Set the output of a given pin, where
 * the bit (plus 32 for GPSET1) is the pin
 * number
 */
#define GPSET0 GPBASE + 0x1c
#define GPSET1 GPBASE + 0x20

/* Clear the output of a given pin */
#define GPCLR0 GPBASE + 0x28
#define GPCLR1 GPBASE + 0x2c

/* Return the current level of a pin */
#define GPLEV0 GPBASE + 0x34
#define GPLEV1 GPBASE + 0x38

/* Record of events on a given pin */
#define GPEDS0 GPBASE + 0x40
#define GPEDS1 GPBASE + 0x44

/* Enable detection of rising edge events
 * (looks for 011 in sync with the sysclk)
 */
#define GPREN0 GPBASE + 0x4c
#define GPREN1 GPBASE + 0x50

/* Enable detection of falling edge events
 * (looks for 100 in sync with the sysclk)
 */
#define GPFEN0 GPBASE + 0x58
#define GPFEN1 GPBASE + 0x5c

/* A high level triggers detection */
#define GPHEN0 GPBASE + 0x64
#define GPHEN1 GPBASE + 0x68

/* A low level triggers detection */
#define GPLEN0 GPBASE + 0x70
#define GPLEN1 GPBASE + 0x74

/* An asynchronous (very short) rising
 * edge transition can be picked up
 */
#define GPAREN0 GPBASE + 0x7c
#define GPAREN1 GPBASE + 0x80

/* An asynchronous (very short) falling
 * edge transition can be picked up
 */
#define GPAFEN0 GPBASE + 0x88
#define GPAFEN1 GPBASE + 0x8c

/* GPIO pull up/down for ALL pins */
#define GPPUD GPBASE + 0x94

/* PUD coarse control values */
#define GPNOPUD 0x0
#define GPENPU  0x1
#define GPENPD  0x2

/* Pull up/down for specific pins
 * Use in conjunction with GPPUD
 */
#define GPPUDCLK0 GPBASE + 0x98
#define GPPUDCLK1 GPBASE + 0x9c

#endif /* INC_GPIO_DAT */
