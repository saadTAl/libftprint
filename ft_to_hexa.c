#include "ft_printf.h"

int ft_to_hexa(unsigned int n, char x)
{

    char *str;
    static int a;

    a = 0;
    if (x == 'X')
    {
        str = "0123456789ABCDEF";

        if (n >= 16)
        {
            if (ft_to_hexa(n / 16, 'X') == -1)
                return (-1);
        }
        if (write(1, &str[n % 16], 1) == -1)
            return (-1);
        else
            a++;
    }
    else
    {
        str = "0123456789abcdef";

        if (n >= 16)
        {
            if (ft_to_hexa(n / 16, 'x') == -1)
                return (-1);
        }
        if (write(1, &str[n % 16], 1) == -1)
            return (-1);
        else
            a++;
    }
    return (a);
}