#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
int main()
{
    close(1);
    //  setvbuf(stdout, NULL, _IONBF, 0);
    int a = ft_printf("%s", "hello");

    int b = printf("%s", "hello");

    dprintf(2, "\n%d\n", a);
    dprintf(2, "%d\n", b);
}