/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:45:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/17 12:47:36 by rdutenke         ###   ########.fr       */
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

int	ft_count_char(char const *s1, char c)
{
	int len;
	int n;
	int i;

	if (!s1)
		return(0);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(join = malloc((len1 + len2 + 1) * sizeof(*join))))
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[len1++] = s2[i];
	join[len1] = '\0';
	return (join);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = -1;
	if (!s1 || !(s = malloc((ft_strlen(s1) + 1) * sizeof(*s))))
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (!(substr = malloc((len + 1) * sizeof(*substr))))
		return (NULL);
	while ((i < len) && (start + i) < slen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
