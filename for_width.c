#include "main.h"

/**
* for_width - checks the width specified if any
* @format: the format string
* @fmt_ind: the index of the format string
* @arglist: the variable argument list
*
* Return: the field width attribute of the argument
*/

int for_width(const char *format, int *fmt_ind, va_list arglist)
{
	int ind, width = FALSE;

	for (ind = *fmt_ind + 1; format[ind] != '\0'; ind++)
	{
		if (format[ind] >= 48 && format[ind] <= 57)
		{
			width *= 10;
			width += format[ind] - 48;
		}
		else if (format[ind] == '*')
		{
			ind++;
			width = va_arg(arglist, int);
			break;
		}
		else
		{
			break;
		}
	}

	*fmt_ind = ind - 1;

	return (width);
}
