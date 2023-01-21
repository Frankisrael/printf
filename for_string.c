#include "main.h"

/**
 * for_string - Prints out a string passed as an argument to _printf().
 * @arglist: List of variable number of arguments passed to _printf().
 * @buffer: Temporary buffer to hold characters to be printed.
 * @flags: Holds the value of flags if available.
 * @width: Minimum width with which the string should be printed.
 * @precision: Number of characters to be printed if given.
 * @l_mod: Length modification.
 *
 * Return: Number of characters printed to standard output.
 */
int for_string(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int i, len = 0, count = 0;
	char *str = va_arg(arglist, char *);

	(void)buffer;
	(void)l_mod;
	if (!str)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len])
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & DASH)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	count = write(1, str, len);
	return (count);
}
