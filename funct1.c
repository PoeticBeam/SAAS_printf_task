#include "main.h"

/*** UNSIGNED NUMBER ***/
/**
 * prnt_unsgnd - Prints an unsigned num
 * @typ: argument list
 * @buffer: Buffer array
 * @flag:  compute active flags
 * @width: get width
 * @accuracy: specify accuracy
 * @size: Size
 * Return: Number of characters printed.
 */
int prnt_unsgnd(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{
	int ii = BUFFER - 2;
	unsigned long int n = va_arg(types, unsigned long int);

	n = size_unsigned_conversion(n, size);

	if (n == 0)
		buffer[ii--] = '0';

	buffer[BUFFER - 1] = '\0';

	while (n > 0)
	{
		buffer[ii--] = (n % 10) + '0';
		n /= 10;
	}

	ii++;

	return (write_unsgnd(0, ii, buffer, flag, width, accuracy, size));
}

/*** UNSIGNED NUMBER IN OCTAL  ***/
/**
 * prnt_oktal - Prints an unsigned number in octal
 * @typ: arguments list
 * @buffer: Buffer array
 * @flag:  Computes active flags
 * @width: width
 * @accuracy: accuracy specification
 * @size: Size
 * Return: Number of characters
 */
int prnt_oktal(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{

	int ii = BUFFER - 2;
	unsigned long int n = va_arg(typ, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);

	n = size_unsigned_conversion(n, size);

	if (n == 0)
		buffer[ii--] = '0';

	buffer[BUFFER - 1] = '\0';

	while (n > 0)
	{
		buffer[ii--] = (n % 8) + '0';
		n /= 8;
	}

	if (flag & F_HASHTAG && init_n != 0)
		buffer[ii--] = '0';

	ii++;

	return (write_unsgnd(0, ii, buffer, flag, width, accuracy, size));
}

/*** UNSIGNED NUMBER IN HEXADECIMAL ***/
/**
 * prnt_hexadec - Prints an unsigned number in hexadecimal
 * @typ: arguments list
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @accuracy: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prnt_hexadec(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{
	return (prnt_hexa(typ, "0123456789abcdef", buffer,
				flag, 'x', width, accuracy, size));
}

/*** UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
 * prnt_hexadec_upper - Prints an unsigned number in upper hexadecimal
 * @typ: arguments lists
 * @buffer: Buffer array
 * @flag:  Computes active flags
 * @width:  width
 * @accuracy: accuracy specification
 * @size: Size
 * Return: Number of characters to be printed
 */
int prnt_hexadec_upper(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{
	return (prnt_hexa(typ, "0123456789ABCDEF", buffer,
				flag, 'X', width, accuracy, size));
}

/*** HEXX NUM IN LOWER OR UPPER ***/
/**
 * prnt_hexa - Prints a hexadecimal number in lower or upper
 * @typ: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_chter: Computes active flags
 * @width: width
 * @accuracy: accuracy spec
 * @size: Size
 * @size: Size
 * Return: Number of characters to be printed
 */
int prnt_hexa(va_list typ, char map_to[], char buffer[],
		int flag, char flag_chter, int width, int accuracy, int size)
{
	int i = BUFFER - 2;
	unsigned long int n = va_arg(typ, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);

	n = size_unsigned_conversion(n, size);

	if (n == 0)
		buffer[ii--] = '0';

	buffer[BUFFER - 1] = '\0';

	while (n > 0)
	{
		buffer[ii--] = map_to[n % 16];
		n /= 16;
	}

	if (flag & FL_HASHTAG && init_n != 0)
	{
		buffer[ii--] = flag_chter;
		buffer[ii--] = '0';
	}

	ii++;

	return (write_unsgnd(0, i, buffer, flag, width, accuracy, size));
}

