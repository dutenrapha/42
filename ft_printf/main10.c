#include "ft_printf.h"
#include <stdio.h>
int main()
{

printf(" --- printf : %d\n", printf("%%"));
ft_printf(" --- ft_printf : %d\n", ft_printf("%%"));
printf("\n");

return (0);
}