
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
        long    number;

        number = n;
        if (number < 0)
        {
                ft_putchar_fd('-', fd);
                number = number * -1;
        }
        if ((number / 10) > 0)
                ft_putnbr_fd(number / 10, fd);
        ft_putchar_fd(number % 10 + 48, fd);

}
