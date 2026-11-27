#include "ft_printf.h"

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
    {
        if (write(1, "(null)", 6) == -1)
            return (-1);
        return (6);
    }
    while (str[i])
    {
        if (write(1, &str[i], 1) == -1)
            return (-1);
        i++;
    }
    return (i);
}
