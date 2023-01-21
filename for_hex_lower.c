#include "main.h"

/**
 * for_hex_lower - Passes a string of hexadecimal values and spec for printing.
 * @arglist: List of variable number of arguments.
 * @buffer: Temporary buffer to hold characters in order to call write() as few
 * times as possible.
 * @flags: Current flag specifications.
 * @width: Value of width specification if any.
 * @precision: Value of precision if any.
 * @l_mod: Constant value of length modifier.
 *
 * Return: Returns the number of characters printed by for_hex().
 */
int for_hex_lower(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int no_of_char_printed;
	char *hex_values = "0123456789abcdef", flag_char = 'x';

	no_of_char_printed = for_hex(arglist, hex_values, buffer,
		flags, flag_char, width, precision, l_mod);

	return (no_of_char_printed);
}
