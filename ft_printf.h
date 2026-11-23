#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *str, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_to_hexa(unsigned n, char x);
int ft_unsigned_decimal(unsigned int n);
int ft_print_adrss(void *p);
int ft_count_digit(long n);

#endif
