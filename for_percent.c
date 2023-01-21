#include "main.h"

/**
 * for_percent - Prints a percent sign.
 * @arglist: List of variable number of arguments taken in by _printf().
 * @buffer: Buffer to hold characters in order to call write() as few times as
 * neccessary.
 * @flags: Hold values of flags in format string.
 * @width: Value of the width specification if any.
 * @precision: Precision specification if any.
 * @l_mod: Length modification specification if given.
 *
 * Return: Returns 1.
 */
int for_percent(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	char c = '%';
	int count = 0;

	(void)arglist;
	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)l_mod;

	count = write(1, &c, 1);

	return (count);
}
