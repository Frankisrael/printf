#include "main.h"

/**
 * for_unsigned - gets an unsigned number, prepends to buffer and passes on
 * @arglist: the list of variable arguments
 * @buffer: a temporary buffer to hold the data
 * @flags: the flag attribute of the argument
 * @width: the field width attribute of the argument
 * @precision: the precision attribute of the argument
 * @l_mod: the length modification attribute of the argument
 *
 * Return: the number of characters printed
 */

int for_unsigned(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int buffer_ind = BUFFSIZE - 2, no_of_char_printed;
	unsigned long int num = va_arg(arglist, unsigned long int);

	buffer[BUFFSIZE - 1] = 0;
	num = conv_l_u(num, l_mod);

	if (num == 0)
		buffer[buffer_ind--] = 48;

	while (num > 0)
	{
		buffer[buffer_ind--] = (num % 10) + 48;
		num /= 10;
	}
	buffer_ind++;

	no_of_char_printed = write_u_to_out(FALSE, buffer_ind, buffer,
			flags, width, precision, l_mod);

	return (no_of_char_printed);
}
