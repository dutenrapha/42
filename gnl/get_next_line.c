/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:43:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/10 07:02:53 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_clean_vector(int len, char vector[])
{
	int i;
	
	i = 0;
	while (i <  len)
	{
		vector[i] = '\0';
		i++;
	}
}

static void	ft_clear_memory(int len_line, char memory[])
{
	int		i;
	int		first;
	char	temp[1000];

	first = 0;
	ft_clean_vector(1000, temp);
	i = 0;
	while (memory[len_line] != '\0')
	{
		if (memory[len_line] == '\n' && first == 0)
		{
			len_line++;
			first = 1;
			continue;
		}
		temp[i] = memory[len_line];
		i++;
		len_line++;
	}
	temp[i] = '\0';
	i = 0;
	while (memory[i] != '\0')
	{
		memory[i] = '\0';
		i++;
	}
	i = 0;
	while (temp[i] != '\0')
	{
		memory[i] = temp[i];
		i++;
	}
}

static char	*ft_set_next_line(char memory[])
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	line = NULL;
	while (memory[len] != '\n')
		len++;
	line = (char *)malloc((len + 1)*sizeof(char));
	line[len] = '\0';
	while (i < len)
	{
		if (memory[i] == '\n')
			continue;
		line[i] = memory[i];
		i++;
	}
	return (line);
}

static void	ft_add(char buf[], char memory[])
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (memory[i] != '\0')
		i++;
	while (buf[j] != '\0')
	{
		memory[i] = buf[j];
		i++;
		j++;
	}
}

int			get_next_line(int fd, char **line)
{
	int				size;
	char			buf[BUFFER_SIZE + 1];
	// static char		memory[INT_MAX];
	static char		memory[1000];

	size = read(fd,buf, BUFFER_SIZE);
	if (size == 0 && memory[0] == '\0')
	{
		return (0);
	}
	else
	{
		if (size > 0)
		{
			ft_add(buf, memory);
			ft_clean_vector(BUFFER_SIZE + 1, buf);
			while (size > 0 && ft_strchr(memory,'\n') == NULL)
			{
				size = read(fd,buf, BUFFER_SIZE);
				if (size > 0)
				{
					ft_add(buf, memory);
					ft_clean_vector(BUFFER_SIZE + 1, buf);
				}
			}
		}
	}
	*line = ft_set_next_line(memory);
	ft_clear_memory(ft_strlen(*line), memory);
	return (1);
}
