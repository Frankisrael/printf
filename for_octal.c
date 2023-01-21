#include "main.h"

/**
 * for_octal - Converts a number to its octal value.
 * @arglist: List of variable number of arguments taken by _printf().
 * @buffer: Temporary buffer to hold characters in order to call write() as few
 * times as possible.
 * @flags: Hold values of flags if available.
 * @width: Value of width specification if available.
 * @precision: Precision specification if available.
 * @l_mod: Length modifier constant if given.
 *
 * Return: Returns the number of characters printed from the call to
 * write_u_to_out() function.
 */
int for_octal(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int buffer_ind = BUFFSIZE - 2, no_of_char_printed;
	unsigned long int num = va_arg(arglist, unsigned long int);
	unsigned long int num_store = num;
	(void)width;

	buffer[BUFFSIZE - 1] = 0;
	num = conv_l_u(num, l_mod);

	if (num == 0)
		buffer[buffer_ind--] = 48;

	while (num > 0)
	{
		buffer[buffer_ind--] = (num % 8) + 48;
		num /= 8;
	}

	if ((flags & HASH) && (num_store != 0))
		buffer[buffer_ind--] = '0';

	buffer_ind++;

	no_of_char_printed = write_u_to_out(FALSE, buffer_ind, buffer, flags,
			width, precision, l_mod);

	return (no_of_char_printed);
}
