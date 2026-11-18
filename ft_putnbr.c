#include "ft.h"

int ft_putnbr(int n)
{
    char c;
    int a;

    a = 0;
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (n < 0)
    {
        n = -n;
        write(1, "-", 1);
        a++;
    }

    if (n >= 10)
    {
        ft_putnbr(n / 10);
        a++;
    }
    c = (n % 10) + '0';
    a += write(1, &c, 1);
    return (a);
}
