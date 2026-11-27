#include "ft_printf.h"

static int ft_helper_printf(char str, va_list args)
{
    int count;

    count = 0;
    if (str == 'c')
        count = ft_putchar(va_arg(args, int));
    else if (str == 'd' || str == 'i')
        count = ft_putnbr(va_arg(args, int));
    else if (str == 'X')
        count = ft_to_hexa(va_arg(args, unsigned int), 'X');
    else if (str == 'x')
        count = ft_to_hexa(va_arg(args, unsigned int), 'x');
    else if (str == '%')
        count = ft_putchar('%');
    else if (str == 's')
        count = ft_putstr(va_arg(args, char *));
    else if (str == 'u')
        count = ft_unsigned_decimal(va_arg(args, unsigned int));
    else if (str == 'p')
        count = ft_print_adrss(va_arg(args, void *));
    return (count);
}

int ft_printf(const char *str, ...)
{
    int i;
    int count;
    int ret;
    va_list args;

    i = 0;
    ret = 0;
    count = 0;
    va_start(args, str);
    while (str[i] && ret != -1)
    {
        if (str[i] == '%' && str[i + 1] == '\0')
            break;
        if (str[i] == '%')
            ret = ft_helper_printf(str[++i], args);
        else
            ret = ft_putchar(str[i]);
        count += ret;
        i++;
    }
    va_end(args);
    if (ret == -1)
        return (-1);
    return (count);
}
