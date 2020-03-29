#include "libft.h"

void ft_bzero(void *s, int nbyte)
{
        int i;
	unsigned char *pointer;

	pointer = (unsigned char *)s;

	i = 0;
        while(i < nbyte)
        {
                *(pointer + i) = '\0';
                i++;
        }
}
