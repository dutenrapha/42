#include "ft_printf.h"
#include <stdio.h>
int main()
{

printf(" --- printf : %d\n", printf("%0-8.5d", 34));
ft_printf(" --- ft_printf : %d\n", ft_printf("%0-8.5d", 34));
printf("\n");

printf(" --- printf : %d\n", printf("%-8.5d", 34));
ft_printf(" --- ft_printf : %d\n", ft_printf("%-8.5d", 34));
printf("\n");

return (0);
}