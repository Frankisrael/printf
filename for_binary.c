#include "main.h"

/**
 * for_binary - Computes and prints the binary value of a decimal number.
 * @arglist: List of variable number of arguments.
 * @buffer: Temporary buffer to hold values in order to call write() as few
 * times as possible.
 * @flags: Flag sepcification if any.
 * @width: Value of width specification if any.
 * @precision: Value of precision if any.
 * @l_mod: Length modifier constant if any.
 *
 * Return: Returns the number of characters printed not calculating the
 * terminating null byte.
 */
int for_binary(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod)
{
	unsigned int quotient, i, total = 0;
	int count = 0;
	unsigned int buff[32];
	char c;
	unsigned int num = va_arg(arglist, unsigned int);

	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)l_mod;

	quotient = 2147483648;
	buff[0] = num / quotient;

	for (i = 1; i < 32; i++)
	{
		quotient /= 2;
		buff[i] = (num / quotient) % 2;
	}

	for (i = 0; i < 32; i++)
	{
		total += buff[i];
		if (total || i == 31)
		{
			c = buff[i] + 48;
			count += write(1, &c, 1);
		}
	}

	return (count);
}
