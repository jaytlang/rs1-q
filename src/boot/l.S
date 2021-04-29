.section .text.init
.global _start

_start:
    mrs x1, mpidr_el1
    and x1, x1, #0x3
    cmp x1, 0
    beq crt0

park:
    wfe
    b park

crt0:
    ldr x1, =startbss
    ldr x2, =ebss
cbss:
    cmp x1, x2
    bge leap
    str xzr, [x1], #8
    b cbss

leap:
    ldr x1, =kstack
    mov sp, x1

    bl kzero
    b park
