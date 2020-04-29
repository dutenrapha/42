/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:44:43 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/29 16:18:26 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s2;
	size_t	i;
	int		j;
	char	*strjoin;
	char	*temp;

	if (!s1 || !s2)
		return (0);
	len_s2 = ft_strlen((char *)s2);
	strjoin = (char *)ft_calloc(ft_strlen((char *)s1)
	+ ft_strlen((char *)s2) + 1, sizeof(char));
	if (!strjoin)
		return (0);
	temp = (char *)ft_calloc(len_s2 + 1, sizeof(char));
	if (!temp)
		return (0);
	i = 0;
	while (*s2 != '\0')
		*(temp + i++) = *s2++;
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		*(strjoin + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (j < len_s2)
		*(strjoin + i++) = *(temp + j++);
	return (strjoin);
}
