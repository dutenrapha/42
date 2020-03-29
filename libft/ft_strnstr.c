#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len_little;
	size_t i;
	size_t j;

	if(*little == '\0')
	{
		return((char *)big);
	}	
	i = 0;
	j = 0;
	len_little = ft_strlen((char *)little);
	
	while(*(big + i) != '\0' && i < len - len_little + 1)
	{
		while(j < len_little)
		{
			if(*(big + i +j) != *(little + j))
			{
				break;
			}
			else if(j == len_little -1)
			{
				return((char *)big + i);
			}
			j++;
		}
		i++;
	}
	return(NULL);
}
