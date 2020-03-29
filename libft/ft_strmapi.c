#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
        int len;
        int i;
        char *strmapi;
	
	if(!s)
	{
		return(NULL);
	}

        i = 0;
        len = ft_strlen(s);

        strmapi = (char *)ft_calloc(len + 1, sizeof(char));
	if(!strmapi)
	{
		return(NULL);
	}

        while(i < len)
        {
                *(strmapi + i) = f(i,*(s + i));
                i++;
        }
        return strmapi;
}
