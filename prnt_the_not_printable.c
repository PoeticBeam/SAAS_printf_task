#include "main.h"

/**
 * prnt_the_not_printable - this function prints the
 * ascii codes in hexadecimal
 * of the non-printable chars
 * @typ: arguments to function
 * @buffer: memory storage handler
 * @flag: Checks available flag specifiers
 * @width: width
 * @accuracy: level of accuracy
 * @size: size
 *
 * Return: returns the specific number of the characters printed
 */

int prnt_the_not_printable(va_list typ, char buffer[],
	int flag, int width, int accuracy, int size)
{
	int x = 0,
	int char_offset = 0;
	char *str = va_arg(typ, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(accuracy);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (printable(str[x]))
			buffer[x + char_offset] = str[x];
		else
			char_offset += hexa_code_appended(str[x], buffer, x + char_offset);

		x++;
	}

	buffer[x + char_offset] = '\0';

	return (write(1, buffer, x + char_offset));
}
