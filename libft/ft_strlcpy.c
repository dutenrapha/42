#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	char *len;
	len = (char *)src;

        if (!dst || !src)
		return (0);
	
	if(size == 0)
	{
		return(ft_strlen(len));
	}

	i = 0;
	while(i < size - 1 && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}

	if(size != 0)
	{
		*(dst + i) = '\0';
	}
	return (ft_strlen(len));
}
