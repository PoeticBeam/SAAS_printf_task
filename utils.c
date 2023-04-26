#include "main.h"

/**
 * printable - this function checks if the character
 * is a printable one
 * @k: k is the character being checked
 *
 * Return: returns 1 for printable characters,
 * 0 for non-printable characters
 */

int printable(char k)
{
	if (k >= 32 && k < 127)
		return (1);

	return (0);
}

/**
 *hexa_code_appended - this function adds the hex format char to buffer
 * @buffer: memory stores characters in array
 * @x: Index at which to start appending.
 * @ascii: ASCII CODE.
 * Return: 3 on success
 */

int hexa_code_appended(char ascii, char buffer[], int x)
{
	char mapsto[] = "0123456789ABCDEF";
	/*
	 * The hexa format code is always 2 digits long
	 */

	if (ascii < 0)
		ascii *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = mapsto[ascii / 16];
	buffer[x] = mapsto[ascii % 16];

	return (3);
}

/**
 * digit - checks if a character is a number/digit
 * @k: this is what is to be evaluated
 *
 * Return: 1 on digit, 0 if not
 */

int digit(char k)
{
	if (k >= '0' && k <= '9')
		return (1);

	return (0);
}

/**
 * size_number_conversion - casts num to size type passed
 * @n: this is the no that will be casted
 * @size: indicates type for casting
 *
 * Return: returns casted n value
 */

long int size_number_conversion(long int n, int size)
{
	if (size == SIZE_LONG)
		return (n);
	else if (size == SIZE_SHORT)
		return ((short)n);

	return ((int)n);
}

/**
 * size_unsigned_conversion - casts numbers indicated as
 * unsigned to the specific size
 * @n: this is the no that will be casted
 * @size: indicates type for casting
 *
 * Return: returns casted n value
 */

long int size_unsigned_conversion(unsigned long int n, int size)
{
	if (size == SIZE_LONG)
		return (n);
	else if (size == SIZE_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
