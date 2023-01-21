#include "main.h"

/**
 * for_rot13 - Encryptes a string using ROT13 letter substitution cipher.
 * @arglist: List of variable number of arguments taken in by _printf().
 * @buffer: Temporary buffer to hold characters before calling write().
 * @flags: Hold values of flags if any.
 * @width: Value of width specification if any.
 * @precision: Value of preicision specification.
 * @l_mod: Length modifier.
 *
 * Return: Returns the number of characters printed to standard output.
 */
int for_rot13(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	int buffer_ind = 0, count = 0, ind, i;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(arglist, char *);
	(void)flags;
	(void)width;
	(void)precision;
	(void)l_mod;

	if (!str)
		str = "(null)";
	for (ind = 0; str[ind]; ind++)
	{
		for (i = 0; alpha[i]; i++)
		{
			if (alpha[i] == str[ind])
			{
				buffer[buffer_ind++] = rot[i];
				break;
			}
		}
		if (alpha[i] == 0)
			buffer[buffer_ind++] = str[ind];
	}
	count = write(1, buffer, buffer_ind);

	return (count);
}
