#include "ft_printf.h"

int ft_unsigned_decimal(unsigned int n)
{
    char c;
    int a;

    a = ft_count_digit(n);
    if (n >= 10)
        if (ft_unsigned_decimal(n / 10) == -1)
            return (-1);
    c = (n % 10) + '0';
    if (write(1, &c, 1) == -1)
        return (-1);
    return (a);
}