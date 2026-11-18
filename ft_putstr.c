#include "ft.h"

int ft_putstr(char *str)
{
    int i;
    int a;

    a = 0;
    i = 0;
    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (5);
    }
    while (str[i])
    {
        a += write(1, &str[i], 1);
        i++;
    }
    return (a);
}
