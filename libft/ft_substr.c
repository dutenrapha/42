#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
        char *substr;
        size_t i;
	
	if(!s || (int)len <= 0 || (int)start < 0 || (int)start > (int)ft_strlen((char *)s) - 1)
	{
		return(NULL);
	}

	substr = (char *)ft_calloc(len + 1,sizeof(char));
	if(!substr)
	{
		return(NULL);
	}

	i = 0;
	while(i < len && *(s + start)!='\0')
	{
		*(substr + i) = *(s + start);
		i++;
		start++;
	}
	*(substr + start) = '\0';
	return substr;
}
