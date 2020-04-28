/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:44:43 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 22:48:25 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*strjoin;
	char	*temp;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	strjoin = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!strjoin)
		return (NULL);
	temp = (char *)ft_calloc(len_s2 + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (*s2 != '\0')
	{
		*(temp + i) = *s2;
		i++;
		s2++;
	}
	i = 0;
	while (i < len_s1)
	{
		*(strjoin + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		*(strjoin + i) = *(temp + j);
		i++;
		j++;
	}
	return (strjoin);
}
