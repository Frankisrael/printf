#include "main.h"
/**
 * for_l_mod - Takes note of the presence or absence of a length modifier.
 * @format: String in which to search for length modifier.
 * @fmt_ind: Index of format string to.
 *
 * Return: Returns the length modifier variable with appropriate specification
 * if any.
 */
int for_l_mod(const char *format, int *fmt_ind)
{
	int l_mod = FALSE;
	int ind = *fmt_ind + 1;

	if (format[ind] == 'l')
		l_mod = LONG;
	else if (format[ind] == 'h')
		l_mod = SHORT;

	if (l_mod == FALSE)
		*fmt_ind = ind - 1;
	else
		*fmt_ind = ind;

	return (l_mod);
}
