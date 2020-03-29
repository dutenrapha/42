#include "libft.h"


void *ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (!(array = (char *)malloc(size * nmemb)))
		return (NULL);
	return (ft_memset(array, 0, size * nmemb));
}
