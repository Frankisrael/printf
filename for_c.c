#include "main.h"

/**
 * for_c - Gets character argument.
 * @arglist: List of variable number of arguments.
 * @buffer: Temporary buffer to hold values in order to call write() as few
 * times as possible.
 * @flags: Flag sepcification if any.
 * @width: Value of width specification if any.
 * @precision: Value of precision if any.
 * @l_mod: Length modifier constant if any.
 *
 * Return: Returns the value from the call to the write_char_to_out() function.
 */
int for_c(va_list arglist, char *buffer, int flags, int width, int precision,
		int l_mod)
{
	char c = va_arg(arglist, int);
	int no_of_char_printed = write_char_to_out(c, buffer, flags, width,
			precision, l_mod);

	return (no_of_char_printed);
}
