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
	int i = 0, j;
	char arg, *str;

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
						break;
					case 's':
						j = 0;
						str = va_arg(print, char*);
						while (str[j] != '\0')
							j++;
						write(1, str, j);
						i = i + 2;
					default:
						write(1, format + i, 1);
						i++;
						break;
				}
			}
			else
			{
				write(1, format + i, 1);
				i++;
			}
		}
	}
	va_end(print);
	return (0);
}
