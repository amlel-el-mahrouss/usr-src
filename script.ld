OUTPUT_ARCH(i386:x86-64)

ENTRY(_start)

PHDRS
{
    null    PT_NULL    FLAGS(0);
    text    PT_LOAD    FLAGS((1 << 0) | (1 << 2));
    rodata  PT_LOAD    FLAGS((1 << 2));
    data    PT_LOAD    FLAGS((1 << 1) | (1 << 2));
}

SECTIONS
{
    . = 1M;

    . += CONSTANT(MAXPAGESIZE);

    .text : {
        . = ALIGN(8);
        *(.text)
    } :text


    . += CONSTANT(MAXPAGESIZE);

    .init_array : {
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
        KEEP (*(.init_array .ctors))
        PROVIDE_HIDDEN (__init_array_end = .);
    }

    . += CONSTANT(MAXPAGESIZE);

    .rodata : {
        *(.rodata .rodata.*)
    } :rodata

    . += CONSTANT(MAXPAGESIZE);

    .data : {
        *(.data .data.*)
    } :data

    . += CONSTANT(MAXPAGESIZE);

    .bss : {
        *(COMMON)
        *(.bss .bss.*)
    } :data

    _KERNEL_HEAP = .;

    . += 0x10000;

    _KERNEL_RAW_HEAP = .;
}
