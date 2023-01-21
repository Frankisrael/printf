#include "main.h"

/**
 * write_num - writes numbers to the standard output
 * @is_neg: a boolean value for th number's sign
 * @ind: the index
 * @buffer: a temporary variable to store data
 * @flags: the flag attribute of the argument
 * @width: the field width  attribute of the argument
 * @precision: the precision  attribute of the argument
 * @l_mod: the length modification  attribute of the argument
 *
 * Return: the number of characters printed
 */

int write_num(int is_neg, int ind, char *buffer, int flags,
		int width, int precision, int l_mod)
{
	int count = 0, len = BUFFSIZE - ind - 1;
	char pad = ' ', ex = 0;

	(void)l_mod;
	if ((flags & ZERO) && !(flags & DASH))
		pad = '0';
	if (is_neg)
		ex = '-';
	else if (flags & PLUS)
		ex = '+';
	else if (flags & SPACE)
		ex = ' ';

	count = write_num_to_out(ind, buffer, flags, width, precision, len, pad, ex);
	return (count);
}

/**
 * write_num_to_out - receives num with flag and pad and prints
 * @ind: the index
 * @buffer: a temporary variable to store data
 * @flags: the flag attribute of the argument
 * @width: the field width  attribute of the argument
 * @precision: the precision  attribute of the argument
 * @pad: the character to pad with
 * @l: the length of characters to be printed
 * @ex: an extra character
 *
 * Return: the number of characters printed
 */

int write_num_to_out(int ind, char *buffer, int flags, int width,
		int precision, int l, char pad, char ex)
{
	int i, count = 0, pad_start = 1;

	if (precision == 0 && ind == BUFFSIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFFSIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	if (precision > 0 && precision < l)
		pad = ' ';
	while (precision > l)
		buffer[--ind] = '0', l++;
	if (ex != 0)
		l++;
	if (width > l)
	{
		for (i = 1; i < width - l + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & DASH && pad == ' ')
		{
			if (ex)
				buffer[--ind] = ex;
			count = write(1, &buffer[ind], l);
			return (count + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & DASH) && pad == ' ')
		{
			if (ex)
				buffer[--ind] = ex;
			count = write(1, &buffer[1], i - 1);
			return (count + write(1, &buffer[ind], l));
		}
		else if (!(flags & DASH) && pad == '0')
		{
			if (ex)
				buffer[--pad_start] = ex;
			count = write(1, &buffer[pad_start], i - pad_start);
			return (count + write(1, &buffer[ind], l - (1 - pad_start)));
		}
	}
	if (ex)
		buffer[--ind] = ex;
	return (write(1, &buffer[ind], l));
}
