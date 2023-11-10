ENTRY(reset)
MEMORY
{
	Memory (rwx) : ORIGIN = 0X00000000, LENGTH = 64M
}
SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		Startup.o(.text)
	}> Memory
	.text :
	{
		*(.text) 
	}> Memory
	.data :
	{
		*(.data) *(.rodata)
	}> Memory
	.bss :
	{
		*(.bss) *(COMMON)
	}> Memory
	. = . + 0x1000;
	Stack_Top = . ;
}