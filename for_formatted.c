#include "main.h"

/**
 * for_formatted - Ultimately sorts out the fate of any wannabe format string.
 * @format: String in which format specifiers are searched.
 * @fmt_ind: Character index in format string.
 * @arglist: List of variable number of arguments passed to _printf().
 * @buffer: Temporary buffer to hold characters so as to allow us call write()
 * as few times as possible.
 * @flags: Values of flag types if any.
 * @width: Value of width specification if any.
 * @precision: Value of precision specifier if any.
 * @l_mod: Constant value of length modifier if any.
 *
 * Return: Number of characters printed if any. -1 on failure.
 */
int for_formatted(const char *format, int *fmt_ind, va_list arglist,
		char *buffer, int flags, int width, int precision, int l_mod)
{
	int i, var = 0, print_total = NON;
	conv_type conv[] = {
		{'d', for_int}, {'i', for_int},
		{'b', for_binary}, {'o', for_octal},
		{'x', for_hex_lower}, {'X', for_hex_upper},
		{'u', for_unsigned}, {'S', for_custom_S},
		{'c', for_c}, {'s', for_string},
		{'%', for_percent}, {'p', for_pointer},
		{'r', for_rev}, {'R', for_rot13},
		{'\0', NULL}
	};
	for (i = 0; conv[i].specifier != '\0'; i++)
		if (format[*fmt_ind] == conv[i].specifier)
			return (conv[i].conv_f(arglist, buffer, flags, width,
						precision, l_mod));

	if (conv[i].specifier == '\0')
	{
		if (format[*fmt_ind] == '\0')
			return (-1);
		var += write(1, "%%", 1);
		if (format[*fmt_ind - 1] == ' ')
		{
			var += write(1, " ", 1);
		}
		else if (width)
		{
			--(*fmt_ind);
			while (format[*fmt_ind] != ' ' &&
					format[*fmt_ind] != '%')
				--(*fmt_ind);
			if (format[*fmt_ind] == ' ')
				--(*fmt_ind);
			return (1);
		}
		var += write(1, &format[*fmt_ind], 1);
		return (var);
	}
	return (print_total);
}
