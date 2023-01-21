#include "main.h"
/**
 * write_u_to_out - writes an unsigned integer to the standard output
 * @ind: the index
 * @is_neg: a boolean sign value
 * @buffer: a temporary buffer to hold the data
 * @flags: the flag attribute of the argument
 * @width: the field width attribute of the argument
 * @precision: the precision attribute of the argument
 * @l_mod: the length modification attribute of the argument
 *
 * Return: the number of characters printed
 */

int write_u_to_out(int is_neg, int ind, char *buffer, int flags,
		int width, int precision, int l_mod)
{
	int l = BUFFSIZE - ind - 1, i = 0;
	char pad = ' ';

	(void)is_neg;
	(void)l_mod;

	if (precision == 0 && ind == BUFFSIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < l)
		pad = ' ';

	while (precision > l)
	{
		buffer[--ind] = '0';
		l++;
	}

	if ((flags & ZERO) && !(flags & DASH))
		pad = '0';

	if (width > l)
	{
		for (i = 0; i < width - l; i++)
			buffer[i] = pad;
		buffer[i] = '\0';

		if (flags & DASH)
		{
			return (write(1, &buffer[ind], l) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], l));
		}
	}

	return (write(1, &buffer[ind], l));
}
