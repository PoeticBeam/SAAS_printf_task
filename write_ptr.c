#include "main.h"

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
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (xtra_char)
				buffer[--ind] = xtra_char;
			return (write(1, &buffer[ind], leng) + write(1, &buffer[3], ii - 3));
		}
		else if (!(flag & FL_MINUS) && padding == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (xtra_char)
				buffer[--ind] = xtra_char;
			return (write(1, &buffer[3], ii - 3) + write(1, &buffer[ind], leng));
		}
		else if (!(flag & FL_MINUS) && padding == '0')

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
