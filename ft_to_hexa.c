#include "ft.h"

int ft_to_hexa(unsigned int n, char x)
{

    char *str;
    int a;

    a = 0;
    if (x == 'X')
    {
        str = "0123456789ABCDEF";

        if (n >= 16)
        {
            a += ft_to_hexa(n / 16, 'X');
        }
        a += write(1, &str[n % 16], 1);
    }
    else
    {
        str = "0123456789abcdef";

        if (n >= 16)
        {
            a += ft_to_hexa(n / 16, 'x');
        }
        a += write(1, &str[n % 16], 1);
    }
    return (a);
}