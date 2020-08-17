/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:43:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/17 16:11:03 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
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

static void	ft_clear_memory(int len_line, char **memory)
{
	char	*temp;
	int		end;

	end = 0;
	end = ft_strchr(*memory, '\0') - ft_strchr(*memory, '\n');
	if (end > 1)
	{
		temp = ft_strdup(*memory);
		free(*memory);
		*memory = NULL;
		if (temp[len_line] == '\n')
		{
			*memory = ft_substr(temp, len_line + 1, end);
		}
		else
		{
			*memory = ft_substr(temp, len_line, end);
		}
		free(temp);
	}
	else
	{
		free(*memory);
		*memory = NULL;
	}
}

static char	*ft_set_next_line(char **memory)
{
	char	*line;
	int		end;

	if (*memory == NULL)
	{
		line = ft_strdup("");
		return(line);
	}
	end = 0;
	if( ft_strchr(*memory, '\n') == NULL)
	{
		end = ft_strlen(*memory);
	}
	else
	{
		end = ft_strchr(*memory, '\0') - ft_strchr(*memory, '\n');
		end = ft_strlen(*memory) - end;
	}
	line = NULL;
	line = ft_substr(*memory, 0, end);
	return (line);
}

static void	ft_add(char **buf, char **memory)
{
	char	*temp;
	if (*memory == NULL)
	{
		*memory  = ft_strdup(*buf);
	}
	else
	{
		temp = NULL;
		temp = ft_strdup(*memory);
		*memory = NULL;
		*memory = ft_strjoin(temp, *buf);
		free(temp);
	}
}

int			get_next_line(int fd, char **line)
{
	int				size;
	char			*buf;
	static char		*memory;
	int 			i;

	i = 0;
	size = -1;
	if (ft_count_char(memory, '\n') < 1)
	{
		while (i < BUFFER_SIZE)
		{
			buf[i] = '\0';
			i++;
		}
		size = read(fd,buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		if (size > 0)
		{
			ft_add(&buf, &memory);
			while (size > 0 && ft_strchr(buf,'\n') == NULL)
			{
				i = 0;
				while (i < BUFFER_SIZE)
				{
					buf[i] = '\0';
					i++;
				}
				size = read(fd,buf, BUFFER_SIZE);
				if (size > 0)
				{

					ft_add(&buf, &memory);
				}
			}
		}
	}
	*line = ft_set_next_line(&memory);
	ft_clear_memory(ft_strlen(*line), &memory);
	if (size == 0 && ft_strlen(memory) == 0)
	// if (size == 0 && (memory == NULL || *memory == '\0') && ft_strlen(*line) == 0)
		return (0);
	else
		return (1);
}
