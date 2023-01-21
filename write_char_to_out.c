#include "main.h"

/**
 * write_char_to_out - writes a character to the standard output
 * @c: the character to be printed
 * @buffer: a temporary buffer to hold the data
 * @flags: the flag attribute of the argument
 * @width: the field width attribute of the argument
 * @precision: the precision attribute of the argument
 * @l_mod: the length modification attribute of the argument
 *
 * Return: the number of characters printed
 */

int write_char_to_out(char c, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int ind = 0, count = 0, count_tot = 0;
	char pad = ' ';
	(void)precision;
	(void)l_mod;

	if (flags & ZERO)
		pad = '0';

	buffer[ind++] = c;
	buffer[ind++] = '\0';

	if (width > 1)
	{
		buffer[BUFFSIZE - 1] = '\0';
		for (ind = 0; ind < width - 1; ind++)
			buffer[BUFFSIZE - ind - 2] = pad;

		if (flags & DASH)
		{
			count = write(1, &buffer[0], 1);
			count_tot = count + write(1, &buffer[BUFFSIZE - ind - 1], width - 1);
			return (count_tot);
		}
		else
		{
			count = write(1, &buffer[BUFFSIZE - ind - 1], width - 1);
			count_tot = count + write(1, &buffer[0], 1);
			return (count_tot);
		}
	}

	return (write(1, &buffer[0], 1));
}
