#include "main.h"

/**
 * scan_accuracy - Calculates the precision for printing
 * @format: Formatted string (prints arguments)
 * @ii: printed argument
 * @list: arguments list.
 *
 * Return: accuracy.
 */
int scan_accuracy(const char *format, int *ii, va_list list)
{
	int urr_i = *ii + 1;
	int accuracy = -1;

	if (format[urr_i] != '.')
		return (accuracy);

	accuracy = 0;

	for (urr_i += 1; format[urr_i] != '\0'; urr_i++)
	{
		if (digit(format[urr_i]))
		{
			accuracy *= 10;
			accuracy += format[urr_i] - '0';
		}
		else if (format[urr_i] == '*')
		{
			urr_i++;
			accuracy = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*ii = urr_i - 1;

	return (accuracy);
}
