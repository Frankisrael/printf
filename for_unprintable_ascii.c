#include "main.h"

/**
 * for_unprintable_ascii - prints strings to the standard out,
 * for non-printable characters, prints '\x'
 * @buffer: a temporary buffer to hold the data
 * @buffer_ind: the current index of the format string
 * @ascii: the ascii
 *
 * Return: 4
 */

int for_unprintable_ascii(char *buffer, int buffer_ind, int ascii)
{
	char range_of_hex[] = "0123456789ABCDEF";

	buffer[buffer_ind++] = '\\';
	buffer[buffer_ind++] = 'x';

	buffer[buffer_ind++] = range_of_hex[ascii / 16];
	buffer[buffer_ind++] = range_of_hex[ascii % 16];

	return (4);
}
