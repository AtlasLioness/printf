#ifndef _MAIN_H
#define _MAIN_H
#include <stddef.h>
#include <stdarg.h>
int _printf(const char *format, ...);

/**
 * struct typep - entry point
 * @p: spec
 * @fun: printer function for specific type
 */
typedef struct typep
{
	char p;
	int (*fun)(va_list);
} spec;

int _putchar(char c);
int print_c(va_list print);
int print_s(va_list print);
int print_d(va_list print);
int print_b(va_list print);
void fct_rec(long int a);
int (*cmp_format(const char a))(va_list);

#endif /* _MAIN_H */
