#include "libftprintf.h"

char	*ft_itoa_hex(uint32_t nb, char* base)
{
	int		cont_num;
	uintmax_t		base_len;
	uint32_t	aux;
	char	*str;

 	base_len = ft_strlen(base);
	cont_num = 1;
	aux = nb;
	str = NULL;
	while ((aux = aux / base_len) > 0)
	cont_num++;
	str = (char *)ft_calloc((cont_num + 1), sizeof(char));
	if (!str)
		return (NULL);
	cont_num--;
	while (cont_num >= 0)
	{
		str[cont_num] = base[nb % base_len];
		nb = nb / base_len;
		cont_num--;
	}
	return (str);
}
