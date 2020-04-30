/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:44:43 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/29 20:42:06 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	int		j;
	t_joi	params;

	if (!s1 || !s2)
		return (0);
	params.len_s2 = ft_strlen((char *)s2);
	params.strjoin = (char *)ft_calloc(ft_strlen((char *)s1)
	+ ft_strlen((char *)s2) + 1, sizeof(char));
	if (!params.strjoin)
		return (0);
	params.temp = (char *)ft_calloc(params.len_s2 + 1, sizeof(char));
	if (!params.temp)
		return (0);
	i = 0;
	while (*s2 != '\0')
		*(params.temp + i++) = *s2++;
	i = -1;
	while (++i < ft_strlen((char *)s1))
		*(params.strjoin + i) = *(s1 + i);
	j = 0;
	while (j < params.len_s2)
		*(params.strjoin + i++) = *(params.temp + j++);
	return (params.strjoin);
}
