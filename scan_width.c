#include "main.h"

/**
 * scan_width - Computes the width
 * @format: Formatted string
 * @ii: arguments list.
 * @list: list of arguments.
 *
 * Return: width.
 */
int scan_width(const char *format, int *ii, va_list list)
{
	int urr_i;
	int width = 0;

	for (urr_i = *ii + 1; format[urr_i] != '\0'; urr_i++)
	{
		if (digit(format[urr_i]))
		{
			width *= 10;
			width += format[urr_i] - '0';
		}
		else if (format[urr_i] == '*')
		{
			urr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*ii = urr_i - 1;

	return (width);
}
