#include "libft.h"

void *ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char *src;
	unsigned char *dest;
	size_t i;
	
	if(str1 == NULL && str2 == NULL)
	{
		return(str1);
	}
	else
	{
		dest = (unsigned char *)str1;
		src = (unsigned char *)str2;
		i = 0;

		while(i < n)
		{
			*(dest + i) = *(src + i);
			i++;
		}

		return(dest);
	}
}
