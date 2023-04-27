#include "main.h"

/**
 * prnt_char - this function prints a character
 * @typ: this contains the arguments to function
 * @buffer: memory buffer takes in characters
 * @flag:  checks for available defined flags
 * @width: Width
 * @accuracy: level of accuracy required in int
 * @size: specifies the size
 *
 * Return: returns the number of the characters present
 */

int prnt_char(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{
	char k = va_arg(typ, int);

	return (write_char_handler(k, buffer, flag, width, accuracy, size));
}

/**
 * prnt_str - this function will print a string
 * @typ: all arguments to function
 * @buffer: memory takes in string
 * @flag:  checks flag specifiers in string
 * @width: get width.
 * @accuracy: accuracy specifier
 * @size: indicates size
 * Return: returns the exact number of characters printed
 */

int prnt_str(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{
	int l = 0, x;
	char *str = va_arg(typ, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(accuracy);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (accuracy >= 6)
			str = "      ";
	}

	while (str[l] != '\0')
		l++;
	if (accuracy >= 0 && accuracy < l)
		l = accuracy;
	if (width > l)
	{
		if (flag & FL_MINUS)
		{
			write(1, &str[0], l);
			for (x = width - l; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - l; x > 0; x--)
				write(1, " ", 1);
			write(1, &str[0], l);
			return (width);
		}
	}
	return (write(1, str, l));

}

/**
 * prnt_prcent - this function will print the percent sign
 * @typ: all arguments to function
 * @buffer: memory storage for characters/strings
 * @flag:  checks available flag specifiers
 * @width: accepts width
 * @accuracy: accuracy
 * @size: size
 *
 * Return: returns the number of characters printed
 */

int prnt_percent(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{

	UNUSED(typ);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(accuracy);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * prnt_int - checks and prints integers
 * @typ: arguments to function
 * @buffer: memory space stores integers
 * @flag:  Checks flag specifier for integer
 * @width: get width.
 * @accuracy: accuracy
 * @size: size
 *
 * Return: returns the number of integers printed
 */

int prnt_integer(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{
	int x = BUFFER - 2;
	int negative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = size_number_conversion(n, size);

	if (n == 0)
		buffer[x--] = '0';
	buffer[BUFFER - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}
	x++;
	return (write_numbr(negative, x, buffer, flag, width, accuracy, size));
}

/**
 * prnt_binary - function prints the binary
 * @typ: arguments to function
 * @buffer: memory space stores
 * @flag:  checks available flag specifiers
 * @width: width
 * @accuracy: accuracy
 * @size: Size specifier
 *
 * Return: returns number of characters that were printed
 */

int prnt_binary(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size)
{
	unsigned int b, c, x, _sum;
	unsigned int ary[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(accuracy);
	UNUSED(size);

	b = va_arg(typ, unsigned int);
	c = 2147483648;
	/*
	 * note this is (2 ^ 31) size of unsigned int
	 */

	ary[0] = b / c;
	for (x = 1; x < 32; x++)
	{
		c /= 2;
		ary[x] = (b / c) % 2;
	}
	for (x = 0, _sum = 0, count = 0; x < 32; x++)
	{
		_sum += ary[x];
		if (_sum || x == 31)
		{
			char y = '0' + ary[x];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
