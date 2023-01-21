#include "main.h"

/**
 * for_flags - Searches for any available flags in a format specification.
 * @format: String in which flag is to be searched.
 * @fmt_ind: Current index in the string.
 *
 * Return: Returns the predetermined value of a flag, if any. Else, returns 0.
 */
int for_flags(const char *format, int *fmt_ind)
{
	int ind, i, flags = 0;
	const char flag_char[] = {'0', '+', '-', '#', ' ', '\0'};
	const int flag_value[6] = {ZERO, PLUS, DASH, HASH, SPACE, 0};

	for (ind = *fmt_ind + 1; format[ind] != '\0'; ind++)
	{
		for (i = 0; flag_char[i] != '\0'; i++)
			if (format[ind] == flag_char[i])
			{
				flags |= flag_value[i];
				break;
			}

		if (flag_char[i] == 0)
			break;
	}

	*fmt_ind = ind - 1;
	return (flags);
}
