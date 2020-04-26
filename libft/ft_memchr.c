#include "libft.h"

void	 *ft_memchr(const void *str, int c, size_t n)
{
	int last;
	size_t i;
	char *string;

	last = 0;
	i = 0;
	string = (char *)str;

	if(*(string) == c && n >0)
	{
		return((char*)str);
	}
	while(i < n)
	{
		if(*(string + i) == c)
		{
			last = i;
			break;
		}
		i++;
	}

	if(last == 0)
		return(NULL);
	else
		return((char*)str + last);
}
