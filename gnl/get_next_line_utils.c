/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:45:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/08 17:01:32 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)s + i);
	}
	else
	{
		return (NULL);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}
