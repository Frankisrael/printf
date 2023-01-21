#include "main.h"

/**
 * for_custom_S - Prints the hexadecimal code for unprintable characters.
 * @arglist: Variable argument list.
 * @buffer: Temporary buffer to hold values in order to call write() as few
 * times as possible.
 * @flags: Flag sepcification if any.
 * @width: Value of width specification if any.
 * @precision: Value of precision if any.
 * @l_mod: Length modifier constant if any.
 *
 * Return: Returns the number of characters printed not calculating the
 * terminating null byte.
 */
int for_custom_S(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	char *str = va_arg(arglist, char *);
	int str_ind = 0, buffer_ind = 0;
	(void)flags;
	(void)width;
	(void)precision;
	(void)l_mod;

	if (!str)
		str = "(null)";

	while (str[str_ind])
	{
		if ((str[str_ind] > 0 && str[str_ind] < 32) ||
				str[str_ind] >= 127)
			buffer_ind += for_unprintable_ascii(buffer, buffer_ind,
					str[str_ind++]);
		else
			buffer[buffer_ind++] = str[str_ind++];
	}
	return (write(1, buffer, buffer_ind));
}
