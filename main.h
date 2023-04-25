#ifndef _MAIN_H
#define _MAIN_H
#include <stddef.h>
#include <stdarg.h>

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

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list print);
int print_s(va_list print);
int print_d(va_list print);
int print_b(va_list print);
void fct_rec(unsigned int a);
void fct_rec_O(unsigned int a);
int (*cmp_format(const char a))(va_list);
int print_u(va_list print);
int print_o(va_list print);
int print_x(va_list print);
int print_X(va_list print);

#endif /* _MAIN_H */
