#include "ft_printf.h"

static int ft_hexa(unsigned long n)
{

    char *str;
    static int a;

    a = 3;
    str = "0123456789abcdef";

    if (n >= 16)
    {
        if (ft_hexa(n / 16) == -1 )
            return (-1) ;
        a++;
    }

    if (write(1, &str[n % 16], 1) == -1)
        return (-1) ;
    return (a);
}

int ft_print_adrss(void *p)
{
    if (p == NULL)
    {
        if (write(1, "(nil)", 5) == -1)
            return (-1);
        return (5);
    }
    if (write(1, "0x", 2) == -1) 
        return (-1) ;

    return (ft_hexa((unsigned long)p));
}
