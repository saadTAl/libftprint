#include "ft_printf.h"

static int ft_hexa(unsigned long n)
{

    char *str;
    static int a;

    a = 3;
    str = "0123456789abcdef";

    if (n >= 16)
    {
        ft_hexa(n / 16);
        a++;
    }

    write(1, &str[n % 16], 1);
    return (a);
}

int ft_print_adrss(void *p)
{
    if (p == NULL)
    {
        write(1, "(nil)", 5);
        return (5);
    }
    write(1, "0x", 2);

    return (ft_hexa((unsigned long)p));
}
