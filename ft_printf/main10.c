#include "ft_printf.h"
#include <stdio.h>
int main()
{

printf(" --- printf : %d\n", printf("%.p", NULL));
ft_printf(" --- ft_printf : %d\n", ft_printf("%.p", NULL));
printf("\n");

return (0);
}