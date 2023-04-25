#include "main.h"
#include <stdarg.h>
/**
 * print_u - prints unsigned integers
 * @print: variadic parameter to print
 *
 * Return: number of integers
 */
int print_u(va_list print)
{
	long int number;
	long int counter, aux_variable, base;

	counter = 0;
	number = va_arg(print, long int);

	if (number < 0)
	{
		number *= -1;
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
* print_o - prints integers in octal
* @print: variadic parameter to print
*
* Return: number of integers
*/
int print_o(va_list print)
{
unsigned int number;
int counter = 0;

number = va_arg(print, unsigned int);
if (number == 0)
{
_putchar('0');
return (1);
}
fct_rec_O(number);
while (number > 0)
{
number = number / 8;
counter++;
}
return (counter);
}
