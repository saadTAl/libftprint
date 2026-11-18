#include "ft.h"

int ft_unsigned_decimal(unsigned int n)
{
    char c;
    int a;

    a = 0;
    if (n >= 10)
        a += ft_unsigned_decimal(n / 10);
    c = (n % 10) + '0';
    a += write(1, &c, 1);
    return (a);
}
