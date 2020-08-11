/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:45:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/10 21:38:11 by rdutenke         ###   ########.fr       */
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

int	ft_count_char(char const *s1, char c)
{
	int len;
	int n;
	int i;

	len = ft_strlen(s1);
	n = 0;
	i = 0;
	while (i < len)
	{
		if (s1[i] == c)
		{
			n++;
		}
		i++;
	}
	return (n);
}