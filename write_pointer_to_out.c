#include "main.h"

/**
 * write_pointer_to_out - prints a pointer to the standard output
 * @ind: the index
 * @buffer: a temporary variable to store data
 * @flags: the flag attribute of the argument
 * @width: the field width  attribute of the argument
 * @l: the length of characters to be printed
 * @ex: an extra character
 * @pad_with: the character to pad with
 * @pad_start: the index to start padding from
 *
 * Return: the number of characters printed
 */

int write_pointer_to_out(char *buffer, int ind, int l,
		int width, int flags, char pad_with, char ex, int pad_start)
{
	int i;

	if (width > l)
	{
		for (i = 3; i < width - l + 3; i++)
			buffer[i] = pad_with;
		buffer[i] = '\0';
		if ((flags & DASH) && pad_with == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (ex)
				buffer[--ind] = ex;
			return (write(1, &buffer[ind], l) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & DASH) && pad_with == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (ex)
				buffer[--ind] = ex;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], l));
		}
		else if (!(flags & DASH) && pad_with == '0')
		{
			if (ex)
				buffer[--pad_start] = ex;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], l - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (ex)
		buffer[--ind] = ex;
	return (write(1, &buffer[ind], BUFFSIZE - ind - 1));
}
