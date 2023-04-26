#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Printf functn
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int ii, printed = 0, printed_chars = 0;
	int flag, width, accuracy, size, buffer_index = 0;
	va_list list;
	char buffer[BUFFER];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (ii = 0; format && format[ii] != '\0'; ii++)
	{
		if (format[ii] != '%')
		{
			buffer[buffer_index++] = format[ii];
			if (buffer_index == BUFFER)
				print_buffer(buffer, &buffer_index);
			/* write(1, &format[ii], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flag = scan_flag(format, &ii);
			width = scan_width(format, &ii, list);
			accuracy = scan_accuracy(format, &ii, list);
			size = scan_size(format, &ii);
			++ii;
			printed = handle_print(format, &ii, list, buffer,
					flag, width, accuracy, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints buffer if it exist
 * @buffer: character arrays
 * @buffer_index: Index added after char,denotes length.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
