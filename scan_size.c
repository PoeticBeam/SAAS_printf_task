#include "main.h"

/**
 * scan_size - Compute the size to cast
 * @format: Formatted string in which to print the arguments
 * @ii: arguments list
 *
 * Return: accuracy.
 */
int scan_size(const char *format, int *ii)
{
	int urr_i = *ii + 1;
	int size = 0;

	if (format[urr_i] == 'l')
		size = SIZE_LONG;
	else if (format[urr_i] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*ii = urr_i - 1;
	else
		*ii = urr_i;

	return (size);
}
