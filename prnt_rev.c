#include "main.h"

/**
 * prnt_rev - this function will print a string in reverse
 * @typ: arguments to function
 * @buffer: memory space storage
 * @flag: Checks for the available flag specifiers
 * @width: width
 * @accuracy: accuracy
 * @size: Size
 *
 * Return: returns the number of characters printed
 */

int prnt_rev(va_list typ, char buffer[],
	int flag, int width, int accuracy, int size)
{
	char *str;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(typ, char *);

	if (str == NULL)
	{
		UNUSED(accuracy);

		str = "(null)";
	}
	for (x = 0; str[x]; x++);

	for (x = x - 1; x >= 0; x--)
	{
		char y = str[x];

		write(1, &y, 1);
		count++;
	}
	return (count);
}
