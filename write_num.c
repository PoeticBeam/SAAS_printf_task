#include "main.h"

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Flags
 * @width: width
 * @acc: accuracy specifier
 * @leng: Number length
 * @padding: Pading char
 * @xtra_char: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flag, int width, int acc,
	int leng, char padding, char xtra_char)
{
	int ii, padding_start = 1;

	if (acc == 0 && ind == BUFFER - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (acc == 0 && ind == BUFFER - 2 && buffer[ind] == '0')
		buffer[ind] = padding = ' '; /* width is displayed with padding ' ' */
	if (acc > 0 && acc < leng)
		padding = ' ';
	while (acc > length)
		buffer[--ind] = '0', leng++;
	if (xtra_char != 0)
		leng++;
	if (width > leng)
	{
		for (ii = 1; ii < width - leng + 1; ii++)
			buffer[ii] = padding;
		buffer[ii] = '\0';
		if (flag & FL_MINUS && padding == ' ')
		{
			if (xtra_char)
				buffer[--ind] = xtra_char;
			return (write(1, &buffer[ind], leng) + write(1, &buffer[1], ii - 1));
		}
		else if (!(flag & FL_MINUS) && padding == ' ')
		{
			if (xtra_char)
				buffer[--ind] = xtra_char;
			return (write(1, &buffer[1], ii - 1) + write(1, &buffer[ind], leng));
		}
		else if (!(flag & FL_MINUS) && padding == '0')
		{
			buffer[--padding_start] = xtra_char;
			return (write(1, &buffer[padding_start], ii - padding_start) +
				write(1, &buffer[ind], leng - (1 - padding_start)));
		}
	}
	if (xtra_char)
		buffer[--ind] = xtra_char;
	return (write(1, &buffer[ind], leng));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flag: Flags specifiers
 * @width: Width specifier
 * @accuracy:  specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int negative, int ind,
	char buffer[],
	int flag, int width, int accuracy, int size)
{
	/* The number is stored at the bufer's right and starts at position ii */
	int leng = BUFFER - ind - 1, ii = 0;
	char padding = ' ';

	UNUSED(negative);
	UNUSED(size);

	if (accuracy == 0 && ind == BUFFER - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (accuracy > 0 && accuracy < leng)
		padding = ' ';

	while (accuracy > leng)
	{
		buffer[--ind] = '0';
		leng++;
	}

	if ((flag & FL_0) && !(flag & FL_MINUS))
		padding = '0';

	if (width > leng)
	{
		for (ii = 0; ii < width - leng; ii++)
			buffer[ii] = padding;

		buffer[ii] = '\0';

		if (flag & FL_MINUS) /* Asign extra char to left of buffer [buffer>padding]*/
		{
			return (write(1, &buffer[ind], leng) + write(1, &buffer[0], ii));
		}
		else /* Asign extra char to left of padding [padding>buffer]*/
		{
			return (write(1, &buffer[0], ii) + write(1, &buffer[ind], leng));
		}
	}

	return (write(1, &buffer[ind], leng));
}

/**
 * write_ptr - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @leng: Length of number
 * @width: Width specifier
 * @flag: Flags specifier
 * @padding: Char representing the padding
 * @xtra_char: Char representing extra char
 * @padding_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_ptr(char buffer[], int ind, int leng,
	int width, int flag, char padding, char xtra_char, int padding_start)
{
	int ii;

	if (width > leng)
	{
		for (ii = 3; ii < width - leng + 3; ii++)
			buffer[ii] = padding;
		buffer[ii] = '\0';
		if (flag & FL_MINUS && padding == ' ')
			/**
			 * Assign extra char to left of buffer
			 */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (xtra_char)
				buffer[--ind] = xtra_char;
			return (write(1, &buffer[ind], leng) + write(1, &buffer[3], ii - 3));
		}
		else if (!(flag & FL_MINUS) && padding == ' ')
			/**
			 * xtra char to the left of buffer
			 */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (xtra_char)
				buffer[--ind] = xtra_char;
			return (write(1, &buffer[3], ii - 3) + write(1, &buffer[ind], leng));
		}
		else if (!(flag & FL_MINUS) && padding == '0')
			/**
			 * xtra xter to left of padding
			 */
		{
			if (xtra_char)
				buffer[--padding_start] = xtra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding_start], ii - padding_start) +
				write(1, &buffer[ind], leng - (1 - padding_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (xtra_char)
		buffer[--ind] = xtra_char;
	return (write(1, &buffer[ind], BUFFER - ind - 1));
}
