#include <param.h>
#include <types.h>
#include <uart1.h>

__attribute__((aligned(16))) char kstack[4096];

void
kzero(void)
{
	u1init(115200);
	print("hello world!\n");
	for(;;)
		;
}
