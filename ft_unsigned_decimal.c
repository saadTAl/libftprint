#include "ft_printf.h"

int ft_unsigned_decimal(unsigned int n)
{
    char c;
    int a;

    a = ft_count_digit(n);
    if (n >= 10)
        ft_unsigned_decimal(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
    return (a);
}