#include "ft_printf.h"
int ft_count_digit(long n)
{
    int i = 0;
    if (n == 0)
        return (1);
    if (n < 0)
    {
        n = -n;
        i++;
    }

    while (n > 0)
    {
        i++;
        n /= 10;
    }
    return (i);
}
int ft_putnbr(int n)
{
    char c;
    int a;

    a = ft_count_digit(n);
    if (n == -2147483648)
    {
        if (write(1, "-2147483648", 11) == -1)
            return (-1);
        return (ft_count_digit(-2147483648));
    }
    if (n < 0)
    {
        n = -n;
        if (write(1, "-", 1) == -1)
            return (-1);
    }
    if (n >= 10)
    {
        if (ft_putnbr(n / 10) == -1)
            return (-1);
    }
    c = (n % 10) + '0';
    if (write(1, &c, 1) == -1)
        return (-1);
    return (a);
}