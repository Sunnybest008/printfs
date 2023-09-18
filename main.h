#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct format - Struct format
 *
 * @specifier: The conversion specifier
 * @f: The function pointer to the corresponding conversion function
 */
typedef struct format
{
	char *specifier;
	int (*f)(va_list);
} format_t;

int _printf(const char *format, ...);
int _putchar(char c);

/* Custom conversion specifiers */
int print_binary(va_list args);
int print_reverse(va_list args);
int print_rot13(va_list args);

/* Conversion functions for standard specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif /* _MAIN_H */
