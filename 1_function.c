#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters
 * printed (excluding the null byte used to
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

			count += handle_format_specifier(args, *format);
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * handle_format_specifier - Handles a
 * format specifier and returns the number
 * of characters printed.
 * @args: The variable argument list.
 * @specifier: The format specifier character.
 *
 * Return: The number of characters printed.
 */
int handle_format_specifier(va_list args, char specifier)
{
	int num = 0;

	if (specifier == 'd' || specifier == 'i')
	{
		num = va_arg(args, int);
		return (print_int(num));
	}

	return (0);
}
/**
 * print_int - Prints an integer.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num / 10)
		count += print_int(num / 10);

	_putchar('0' + num % 10);
	return (count + 1);
}
