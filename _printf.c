#include "main.h"
#include <stdarg.h>
/**
 *_printf - function that produces output according to a format.
 * @format: format of parameter to print
 *
 * Return: number of elements printed or -1 if failure
 */
int _printf(const char *format, ...)
{
	va_list print;
	int i, counter = 0;

	if (format == NULL)
		return (-1);

	va_start(print, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
				counter++;
			}
			else if (cmp_format(format[i + 1]) != NULL)
			{
				counter += (cmp_format(format[i + 1]))(print);
				i++;
			}
			else
			{
				_putchar(format[i]);
				counter++;
			}
		}
		else
		{
			_putchar(format[i]);
			counter++;
		}
	}
	va_end(print);
	return (counter);
}
/**
 * cmp_format - entry point
 * @a: character
 *
 * Return: 0
 */
int (*cmp_format(const char a))(va_list)
{
	spec all[] = {
	{'c', print_c},
	{'s', print_s},
	{'i', print_d},
	{'d', print_d},
	{'b', print_b},
	{'o', print_o},
	{'u', print_u},
	{'\0', NULL}
	};
	int k;

	for (k = 0; all[k].p != '\0'; k++)
	{
		if (all[k].p == a)
			return (all[k].fun);
	}
	return (0);
}
