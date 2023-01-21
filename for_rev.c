#include "main.h"

/**
 * for_rev - A custom specifier to print a string in reverse.
 * @arglist: List of variable number of arguments to _printf().
 * @buffer: Temporary buffer to hold characters in order to call write() as few
 * times as neccessary.
 * @flags: Holds values of flags if any.
 * @width: Value of width specification.
 * @precision: Precision specification for which to print the string.
 * @l_mod: Length modifier.
 *
 * Return: Returns the number of characters printed to standard output.
 */
int for_rev(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int buffer_ind = 0;
	int ind = 0, count = 0;
	char *str = va_arg(arglist, char *);
	(void)flags;
	(void)width;
	(void)precision;
	(void)l_mod;

	if (!str)
		str = "(null)";

	while (str[ind])
		ind++;

	for (ind = ind - 1; ind >= 0; ind--)
		buffer[buffer_ind++] = str[ind];

	count = write(1, buffer, buffer_ind);

	return (count);
}
