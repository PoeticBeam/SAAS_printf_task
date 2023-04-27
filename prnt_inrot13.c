#include "main.h"

/**
 * prnt_inrot13 - prints a string in rot13 encryption
 * @typ: arguments to function
 * @buffer: memory storage space
 * @flag: Checks for available flag specifiers
 * @width: width
 * @accuracy: accuracy
 * @size: size
 *
 * Return: returns the number of characters printed
 */

int prnt_inrot13(va_list typ, char buffer[],
	int flag, int width, int accuracy, int size)
{
	char x;
	char *str;
	unsigned int a;
	unsigned int b;

	int count = 0;

	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(accuracy);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; input[b]; b++)
		{
			if (input[b] == str[a])
			{
				x = output[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!input[b])
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
