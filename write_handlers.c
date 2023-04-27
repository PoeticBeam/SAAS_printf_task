#include "main.h"

/** WRITE HANDLE ***/
/**
 * handle_write_char - Prints a string
 * @k: char types.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @width: get width.
 * @accuracy: accuracy
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_char_handler(char k, char buffer[],
	int flag, int width, int accuracy, int size)
{ /* char is stored at left and paddind at buffer's right */
	int ii = 0;
	char padding = ' ';

	UNUSED(accuracy);
	UNUSED(size);

	if (flag & FL_0)
		padding = '0';

	buffer[ii++] = k;
	buffer[ii] = '\0';

	if (width > 1)
	{
		buffer[BUFFER - 1] = '\0';
		for (ii = 0; ii < width - 1; ii++)
			buffer[BUFFER - ii - 2] = padding;

		if (flag & FL_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER - ii - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER - ii - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @accuracy: accuracy specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_numbr(int negative, int ind, char buffer[],
	int flag, int width, int accuracy, int size)
{
	int leng = BUFFER - ind - 1;
	char padding = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & FL_0) && !(flag & FL_MINUS))
		padding = '0';
	if (negative)
		extra_ch = '-';
	else if (flag & FL_PLUS)
		extra_ch = '+';
	else if (flag & FL_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flag, width, accuracy,
		leng, padding, extra_ch));
}
