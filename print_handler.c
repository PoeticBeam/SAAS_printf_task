#include "main.h"

/**
 * handle_print - Prints type argument
 * @frmt: Formatted string
 * @list: List of arguments
 * @ind: ind.
 * @buffer: Buffer array
 * @flag: Computes active flags
 * @width: scan width.
 * @accuracy: accuracy specification
 * @size: Size
 * Return: 1 or 2;
 */
int handle_print(const char *frmt, int *ind, va_list list, char buffer[],
		int flag, int width, int accuracy, int size)
{
	int ii, unknown_length = 0, prntd_chars = -1;
	frmtt frmt_typ[] = {
		{'c', prnt_char}, {'s', prnt_str}, {'%', prnt_prcent},
		{'i', prnt_integer}, {'d', prnt_integer}, {'b', prnt_binary},
		{'u', prnt_unsgnd}, {'o', prnt_oktal}, {'x', prnt_hexadec},
		{'X', prnt_hexadec_upper}, {'p', prnt_ptr}, {'S', prnt_the_not_printable},
		{'r', prnt_rev}, {'R', prnt_inrot13}, {'\0', NULL}
	};
	for (ii = 0; frmt_typ[ii].frmt != '\0'; ii++)
		if (frmt[*ind] == frmt_typ[ii].frmt)
			return (frmt_typ[ii].func(list, buffer, flag, width, accuracy, size));

	if (frmt_typ[ii].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_length += write(1, &frmt[*ind], 1);
		return (unknown_length);
	}
	return (prntd_chars);
}
