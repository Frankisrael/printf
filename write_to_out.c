#include "main.h"

/**
 * write_to_out - writes a character to the standard output
 * @buffer: a temporary buffer to store the data
 * @buffer_ind: the buffer index
 *
 * Return: void
 */

void write_to_out(char *buffer, int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}
