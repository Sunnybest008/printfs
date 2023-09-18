#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
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
 * handle_format_specifier - Handles a format specifier
 * and returns the number
 * of characters printed.
 * @args: The variable argument list.
 * @specifier: The format specifier character.
 * Return: The number of characters printed.
 */
int handle_format_specifier(va_list args, char specifier)
{
	int num = 0;

	if (specifier == 'u' || specifier == 'o' ||
			specifier == 'x' || specifier == 'X')
	{
		num = va_arg(args, int);
		return (print_base(num, specifier));
	}

	return (0);
}
/**
 * print_base - Prints an integer in
 * the specified base (u, o, x, X).
 * @num: The integer to print.
 * @base: The base (u, o, x, X).
 *
 * Return: The number of characters printed.
 */
int print_base(int num, char base)
{
	int count = 0;
	char *digits = "0123456789ABCDEF";
	int is_negative = 0;

	if (base == 'u' && num < 0)
		return (0);

	if (base == 'd' || base == 'i')
	{
		if (num < 0)
		{
			_putchar('-');
			count++;
			num = -num;
			is_negative = 1;
		}
	}

	count += recursive_print_base(num, base, digits);

	return (count);
}
/**
 * recursive_print_base - Recursively prints
 * an integer in the specified base.
 * @num: The integer to print.
 * @base: The base (u, o, x, X).
 * @digits: The string of digits for the base.
 *
 * Return: The number of characters printed.
 */
int recursive_print_base(int num, char base, char *digits)
{
	int count = 0;

	if (num / 16)
		count += recursive_print_base(num / 16, base, digits);

	_putchar(digits[num % 16]);
	return (count + 1);
}
