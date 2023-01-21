#include "main.h"

/**
 * for_int - Gets integer, sorts out the sign and length modifier, and passes.
 * @arglist: List of variable number of arguments.
 * @buffer: Temporary buffer for holding characters in order to call write()
 * as few times as possible.
 * @flags: Stores flag specifications.
 * @width: Value of width specification if any.
 * @precision: Value of precision specification if any.
 * @l_mod: Length modifier constant.
 *
 * Return: Returns the number of characters printed by write_num().
 */
int for_int(va_list arglist, char *buffer, int flags, int width, int precision,
		int l_mod)
{
	int buffer_ind = BUFFSIZE - 2, count = 0, is_neg = FALSE;
	long int s_num = va_arg(arglist, long int);
	unsigned long int u_num;

	s_num = conv_l_signd(s_num, l_mod);

	if (s_num == 0)
		buffer[buffer_ind--] = 48;

	buffer[BUFFSIZE - 1] = '\0';
	u_num = (unsigned long int)s_num;

	if (s_num < 0)
	{
		u_num = (unsigned long int)(s_num * -1);
		is_neg = TRUE;
	}

	while (u_num > 0)
	{
		buffer[buffer_ind--] = (u_num % 10) + 48;
		u_num /= 10;
	}
	buffer_ind++;

	count = write_num(is_neg, buffer_ind, buffer, flags, width,
			precision, l_mod);

	return (count);
}
