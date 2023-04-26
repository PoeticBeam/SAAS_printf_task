#include "main.h"

/**
 * scan_flag - Computes active flags
 * @format: Formatted string (prints arguments)
 * @ii: takes a parameter.
 * Return: Flags:
 */
int scan_flag(const char *format, int *ii)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int g, urr_i;
	int flag = 0;
	const char FLAG_CHTER[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARRAY[] = {FL_MINUS, FL_PLUS, FL_0, FL_HASHTAG, FL_SPACE, 0};

	for (urr_i = *ii + 1; format[urr_i] != '\0'; urr_i++)
	{
		for (g = 0; FLAG_CHTER[g] != '\0'; g++)
			if (format[urr_i] == FLAG_CHTER[g])
			{
				flag |= FLAG_ARRAY[g];
				break;
			}

		if (FLAG_CHTER[g] == 0)
			break;
	}

	*ii = urr_i - 1;

	return (flag);
}
