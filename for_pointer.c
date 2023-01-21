#include "main.h"

/**
 * for_pointer - Gets the hexadecimal value of a pointer.
 * @arglist: List of variable number of arguments taken in by _printf().
 * @buffer: Buffer to hold characters in order to call write() as few times as
 * neccessary.
 * @flags: Hold values of flags in format string.
 * @width: Value of the width specification if any.
 * @precision: Precision specification if any.
 * @l_mod: Length modification specification if given.
 *
 * Return: Number of characters printed out by write_pointer_to_out().
 */
int for_pointer(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int buffer_ind = BUFFSIZE - 2, l = 2, pad_start = 1;
	char ex = FALSE, pad_with = ' ';
	unsigned long val_address;
	char *assign = "0123456789abcdef";
	void *address = va_arg(arglist, void *);
	(void)width;
	(void)l_mod;
	(void)precision;

	if (!address)
	{
		address = "(nil)";
		return (write(1, address, 5));
	}
	buffer[BUFFSIZE - 1] = 0;
	val_address = (unsigned long)address;

	while (val_address > 0)
	{
		buffer[buffer_ind--] = assign[val_address % 16];
		val_address /= 16;
		l++;
	}

	if ((flags & ZERO) && !(flags & DASH))
		pad_with = '0';
	if (flags & PLUS)
	{
		ex = '+';
		l++;
	}
	else if (flags & SPACE)
	{
		ex = ' ';
		l++;
	}
	buffer_ind++;

	return (write_pointer_to_out(buffer, buffer_ind, l, width, flags,
				pad_with, ex, pad_start));
}
