#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t i;
	unsigned char *string1;
	unsigned char *string2;

	string1 = (unsigned char *)str1;
	string2 = (unsigned char *)str2;
	
	i = 0;
	while(i < n)
	{
		if(*(string1 + i) != *(string2 + i) )
		{
			return *(string1 + i) - *(string2 + i);
		}
		i++;
	}
	return 0;
}
