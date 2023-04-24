#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list print;
	int i = 0, j, counter = 0;
	char arg, *str;

	if (format == NULL)
		return (-1);
	va_start(print, format);
	if (format)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				switch (format[i + 1])
				{
					case 'c':
						arg = va_arg(print, int);
						write(1, &arg, 1);
						i = (i + 1) + 1;
						counter++;
						break;
					case 's':
						j = 0;
						str = va_arg(print, char*);
						while (str[j] != '\0')
							j++;
						write(1, str, j);
						i = i + 2;
						counter += j - 1;
						break;
					case '%':
						write(1, format + i, 1);
						i = i + 2;
						counter++;
						break;
					case '\0':
						return (-1);
					default:
						write(1, format + i, 1);
						counter++;
						i++;
						break;
				}
			}
			else
			{
				write(1, format + i, 1);
				counter++;
				i++;
			}
		}
	}
	va_end(print);
	return (counter);
}
