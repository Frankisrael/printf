#include "main.h"

/**
 * _printf - prints formatted data to the standard output
 * @format: the obligatory parameter that contains the format
 * specifiers for the succeeding arguments
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int fmt_ind, printed = FALSE, print_total = 0, buffer_ind = 0;
	int flags, width, precision, l_mod;
	char buffer[BUFFSIZE];
	va_list arglist;

	if (!format)
		return (-1);

	va_start(arglist, format);

	for (fmt_ind = 0; format[fmt_ind]; fmt_ind++)
	{
		if (format[fmt_ind] == '%')
		{
			write_to_out(buffer, &buffer_ind);
			flags = for_flags(format, &fmt_ind);
			width = for_width(format, &fmt_ind, arglist);
			precision = for_precision(format, &fmt_ind, arglist);
			l_mod = for_l_mod(format, &fmt_ind);
			fmt_ind++;

			printed = for_formatted(format, &fmt_ind, arglist,
					buffer, flags, width, precision, l_mod);
			if (printed == -1)
				return (-1);

			print_total += printed;
		}
		else
		{
			buffer[buffer_ind++] = format[fmt_ind];
			if (buffer_ind == BUFFSIZE)
				write_to_out(buffer, &buffer_ind);
			print_total++;
		}
	}
	va_end(arglist);
	write_to_out(buffer, &buffer_ind);

	return (print_total);
}
