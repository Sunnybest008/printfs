#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
