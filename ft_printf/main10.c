#include "ft_printf.h"
#include <stdio.h>
int main()
{

printf(" --- printf : %d\n", printf("%.", 1234));
ft_printf(" --- ft_printf : %d\n", ft_printf("%.", 1234));
printf("\n");


// printf(" --- printf : %d\n", printf("%.5p", 0));
// ft_printf(" --- ft_printf : %d\n", ft_printf("%.5p", 0));
// printf("\n");

return (0);
}