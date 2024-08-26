/*
 * linker_script.ld
 *
 *      Author: Mina Karam 
 */
 
 MEMORY
{
	flash(RX) : ORIGIN = 0X08000000 , LENGTH = 128K
	sram(RWX) : ORIGIN = 0X20000000 , LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_E_TEXT = .;
	}>flash
	.data : {
		_S_DATA = .;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = .;
	}>sram AT> flash
	.BSS : {
		_S_BSS = .;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = .;
	}>sram
	.comment : {
		*(.comment*)
	}>flash
	. = ALIGN(4);
	. = . + 0X1000;
	stack_top = .;
}