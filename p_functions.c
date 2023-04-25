#include "main.h"
#include <stdarg.h>
#include <unistd.h>
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

/**
 * print_d - prints integers
 * @print: variadic parameter to print
 *
 * Return: number of integers
 */
int print_d(va_list print)
{
	long int number;
	int counter, aux_variable, base;

	counter = 0;
	number = va_arg(print, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		counter++;
	}
	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		counter++;
	}
	if (number > 9)
	{
		base = 10;

		while (number / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			counter++;
		}
	}
	return (counter);
}

/**
 * print_b - prints integers in binary
 * @print: variadic parameter to print
 *
 * Return: number of integers
 */
int print_b(va_list print)
{
	long int number;
	int counter = 0;

	number = va_arg(print, int);
	fct_rec(number);
	while (number > 0)
	{
		number = number / 2;
		counter++;
	}
	return (counter);
}
