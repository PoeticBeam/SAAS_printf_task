#include "main.h"

/**
 * prnt_ptr - this function outputs the
 * value stored in pointer variable
 * @typ: arguments to function
 * @buffer: memory storage
 * @flag: Checks for the available flag specifiers
 * @width: width
 * @accuracy: accuracy
 * @size: Size
 *
 * Return: returns the number of characters printed
 */

int prnt_ptr(va_list typ, char buffer[],
	int flag, int width, int accuracy, int size)
{
	char xtra_char = 0, padding = ' ';
	int ind = BUFFER - 2, leng = 2, padding_start = 1;
	/*
	 * leng = 2, pre-formatting for lower case hexadecimal '0x'
	 */
	unsigned long number_address;
	char mapsto[] = "0123456789abcdef";
	void *address = va_arg(typ, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFFER - 1] = '\0';
	UNUSED(accuracy);

	number_address = (unsigned long)address;
	while (number_address > 0)
	{
		buffer[ind--] = mapsto[number_address % 16];
		number_address /= 16;
		leng++;
	}
	if ((flag & FL_0) && !(flag & FL_MINUS))
		padding = '0';
	if (flag & FL_PLUS)
		xtra_char = '+', leng++;
	else if (flag & FL_SPACE)
		xtra_char = ' ', leng++;
	ind++;

	/*
	 * recall that we are returning
	 * (write(1, &buffer[x], BUFFER - x - 1));
	 */

	return (write_ptr(buffer, ind, leng,
		width, flag, padding, xtra_char, padding_start));
}
