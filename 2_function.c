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
			format++; /*Move past '%'*/
			if (*format == '\0')
				break;

			count += handle_format_specifier(args, *format);
		}
		format++;
	}

	va_end(args);
	return (count);
}
/**
 * handle_format_specifier - Handles a format
 * specifier and returns the number
 * of characters printed.
 * @args: The variable argument list.
 * @specifier: The format specifier character.
 *
 * Return: The number of characters printed.
 */
int handle_format_specifier(va_list args, char specifier)
{
	if (specifier == 'c')
	{
		char c = va_arg(args, int);

		_putchar(c);
		return (1);
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";
		return (print_string(str));
	}
	else if (specifier == '%')
	{
		_putchar('%');
		return (1);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);

		return (print_int(num));
	}
	else if (specifier == 'b')
	{
		unsigned int num = va_arg(args, unsigned int);

		return (print_binary(num));
	}
	else
	{
		_putchar('%');
		_putchar(specifier);
		return (2);
	}
}
