#include "ft.h"

int ft_putchar(char c)
{
    int a;
    a = 0;
    a += write(1, &c, 1);
    return (a);
}
