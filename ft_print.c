#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    int i;
    int count;
    va_list args; 

    i = 0;
    count = 0;
    va_start(args, str);

    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[++i] != '\0')
            {
                if (str[i] == 'c')
                    count += ft_putchar(va_arg(args, int));
                else if (str[i] == 'd' || str[i] == 'i')
                    count += ft_putnbr(va_arg(args, int));
                else if (str[i] == 'X')
                    count += ft_to_hexa(va_arg(args, unsigned int), 'X');
                else if (str[i] == 'x')
                    count += ft_to_hexa(va_arg(args, unsigned int), 'x');
                else if (str[i] == '%')
                    count += ft_putchar('%');
                else if (str[i] == 's')
                    count += ft_putstr(va_arg(args, char *));
                else if (str[i] == 'u')
                    count += ft_unsigned_decimal(va_arg(args, unsigned int));
                else if (str[i] == 'p')
                    count += ft_print_adrss(va_arg(args, void *));
            }
            else
                break;
        }

        else
        {
            count += ft_putchar(str[i]);
        }
        i++;
    }
    va_end(args);
    return (count);
}
