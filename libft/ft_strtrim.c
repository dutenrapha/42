#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	size_t len;
	char *zero = (char *)ft_calloc(1,sizeof(char));
	if(!zero)
		return(NULL);

	if(!s1 || !set)
		return(NULL);

	while(*s1 && ft_strchr(set, *s1) != NULL)
	{
		s1++;
	}

	len = ft_strlen(s1);
	
	if(len ==0)
	{
		return(zero);
	}	

	while(len && ft_strchr(set, *(s1 + len - 1)) != NULL)
	{
		len--;
	}
	
	return(ft_substr((char *)s1, 0, len));
}
