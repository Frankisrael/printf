#include "main.h"

/**
 * for_hex - Gets hex values to assign and prints in specified case.
 * @arglist: List of variable number of arguments to _printf().
 * @assign: String of hexadecimal values from which to assign.
 * @buffer: Temporary buffer to hold characters in order to call write() as few
 * times as possible.
 * @flags: Flag specification if any.
 * @flag_char: Character value of the flag given.
 * @width: Width specification if any.
 * @precision: Precision specification if any.
 * @l_mod: Length modifier constant if any.
 *
 * Return: Returns the number of characters written.
 */
int for_hex(va_list arglist, char *assign, char *buffer, int flags,
		char flag_char, int width, int precision, int l_mod)
{
	int buffer_ind = BUFFSIZE - 2, no_of_char_printed;
	unsigned long int num = va_arg(arglist, unsigned long int);
	unsigned long int num_store = num;

	(void)width;

	num = conv_l_u(num, l_mod);
	buffer[BUFFSIZE - 1] = 0;

	if (num == 0)
		buffer[buffer_ind--] = 48;

	while (num > 0)
	{
		buffer[buffer_ind--] = assign[num % 16];
		num /= 16;
	}

	if ((flags & HASH) && (num_store != 0))
	{
		buffer[buffer_ind--] = flag_char;
		buffer[buffer_ind--] = 48;
	}

	buffer_ind++;

	no_of_char_printed = write_u_to_out(FALSE, buffer_ind, buffer, flags,
			width, precision, l_mod);

	return (no_of_char_printed);
}
