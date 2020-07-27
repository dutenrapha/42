#include "ft_printf.h"
#include <stdio.h>
int main()
{

printf(" --- printf : %d\n", printf("%.", 1234));
ft_printf(" --- ft_printf : %d\n", ft_printf("%.", 1234));
printf("\n");


printf(" --- printf : %d\n", printf("%05", 0));
ft_printf(" --- ft_printf : %d\n", ft_printf("%05", 0));
printf("\n");

printf(" --- printf : %d\n", printf("%0", 0));
ft_printf(" --- ft_printf : %d\n", ft_printf("%0", 0));
printf("\n");

printf(" --- printf : %d\n", printf("%5%", 0));
ft_printf(" --- ft_printf : %d\n", ft_printf("%5%", 0));
printf("\n");

printf(" --- printf : %d\n", printf("%05%", 0));
ft_printf(" --- ft_printf : %d\n", ft_printf("%05%", 0));
printf("\n");

return (0);
}