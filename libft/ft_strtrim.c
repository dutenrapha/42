/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:04:38 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 23:06:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*zero;

	zero = (char *)ft_calloc(1, sizeof(char));
	if (!zero)
		return (NULL);
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
	{
		s1++;
	}
	len = ft_strlen(s1);
	if (len == 0)
	{
		return (zero);
	}
	while (len && ft_strchr(set, *(s1 + len - 1)) != NULL)
	{
		len--;
	}
	return (ft_substr((char *)s1, 0, len));
}
