#include "main.h"

/**
 * for_precision - Checks if precision spec is given and computes value.
 * @format: Format string in which to search for precision specification.
 * @fmt_ind: Index of format string.
 * @arglist: List of variable number of arguments passed to _printf().
 *
 * Return: Returns the precision value if any.
 */
int for_precision(const char *format, int *fmt_ind, va_list arglist)
{
	int ind = *fmt_ind + 1;
	int precision = NON;

	if (format[ind] != '.')
		return (precision);
	precision = YES;

	for (ind = ind + 1; format[ind] != '\0'; ind++)
	{
		if (format[ind] >= 48 && format[ind] <= 57)
		{
			precision *= 10;
			precision += format[ind] - 48;
		}
		else if (format[ind] == '*')
		{
			ind++;
			precision = va_arg(arglist, int);
			break;
		}
		else
		{
			break;
		}
	}
	*fmt_ind = ind - 1;

	return (precision);
}
