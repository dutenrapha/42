#include "ft_printf.h"
#include <stdio.h>
int main()
{

printf(" --- printf : %d\n", printf("%5%"));
ft_printf(" --- ft_printf : %d\n", ft_printf("%5%"));
printf("\n");

return (0);
}