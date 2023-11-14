#include "main.h"

/**
 * _printf - a function that replicates what printf does
 * @format: character string
 * Return: what is called
 */
int _printf(const char *format, ...)
{
	int character = 0;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			character++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				character++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list, int);

				write(1, &c, 1);
				character++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char*);
				int st = 0;

				while (str[st] != '\0')
					st++;
				write(1, str, st);
				character += st;
			}
		}
		format++;
	}
	va_end(list);
	return (character);
}
