#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _putchar - prints a character
 * @c: char to print
 *
 * Return: 1 success, -1 error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_c - prints char from variadic function
 * @print: char to print
 *
 * Return: always 1 (success)
 */

int print_c(va_list print)
{
	_putchar(va_arg(print, int));
	return (1);
}

/**
 * print_s - prints string
 * @print: variadic parameter to print
 *
 * Return: number of elements printed
 */

int print_s(va_list print)
{
	char *str;
	int i;

	str = va_arg(print, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
	}
	return (i);
}
