#include "main.h"

/**
 * conv_l_signd - Casts a signed number based on the length specification.
 * @num: Number for which length should be modified.
 * @l_mod: Length modification specification.
 *
 * Return: Returns the number casted to its appropriate length specification.
 */
long int conv_l_signd(long int num, int l_mod)
{
	if (l_mod == LONG)
		return (num);
	else if (l_mod == SHORT)
		return ((short int)num);
	else
		return ((int)num);
}

/**
 * conv_l_u - Casts an unsigned number based on the length specification.
 * @num: Unsigned number for which length should be modified.
 * @l_mod: Length modification specification.
 *
 * Return: Returns the number casted to its appropriate length specification.
 */
long int conv_l_u(unsigned long int num, int l_mod)
{
	if (l_mod == LONG)
		return (num);
	else if (l_mod == SHORT)
		return ((unsigned short)num);
	else
		return ((unsigned int)num);
}
