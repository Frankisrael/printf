#include "main.h"

/**
 * for_hex_upper - Passes a string of uppercase hexadecimal values and spec
 * to for_hex() for printing.
 * @arglist: List of variable number of arguments passed to _printf().
 * @buffer: Temporary buffer to hold characters and enable us call write() as
 * few times as possible.
 * @flags: Flags present.
 * @width: Value of width specification if any.
 * @precision: Value of precision to which to write output.
 * @l_mod: Length modification specification if any.
 *
 * Return: Returns the number of characters printed by the for_hex() function.
 */
int for_hex_upper(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int no_of_char_printed;
	char *hex_values = "0123456789ABCDEF", flag_char = 'X';

	no_of_char_printed = for_hex(arglist, hex_values, buffer,
		flags, flag_char, width, precision, l_mod);

	return (no_of_char_printed);
}
