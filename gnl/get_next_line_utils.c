/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:45:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/19 08:39:32 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size1;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	i = ft_strlen(s2);
	new = (char *)malloc((sizeof(char) * (size1 + i + 1)));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new[size1 + i] = s2[i];
		i++;
	}
	new[size1 + i] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*point;
	int		i;
	int		len;

	i = 0;
	len = 0;
	len = ft_strlen(s1);
	point = (char *)malloc(sizeof(char) * (len + 1));
	if (point == 0)
		return (0);
	while (*(s1 + i) != '\0')
	{
		*(point + i) = *(s1 + i);
		i++;
	}
	*(point + i) = '\0';
	return (point);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int)len <= 0 || (int)start < 0 ||
	(int)start > (int)ft_strlen((char *)s) - 1)
	{
		return (ft_strdup(""));
	}
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
	{
		return (0);
	}
	i = 0;
	while (i < len && *(s + start) != '\0')
	{
		*(substr + i) = *(s + start);
		i++;
		start++;
	}
	*(substr + i) = '\0';
	return (substr);
}
