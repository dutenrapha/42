/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:43:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/11 08:22:46 by rdutenke         ###   ########.fr       */
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
	char	temp[1000];

	ft_clean_vector(1000, temp);
	i = 0;
	while (memory[len_line] != '\0')
	{
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

	size = -1;
	if (ft_count_char(memory, '\n') < 1)
	{
		ft_clean_vector(BUFFER_SIZE + 1, buf);
		size = read(fd,buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		if (size > 0)
		{
			ft_add(buf, memory);
			while (size > 0 && ft_strchr(buf,'\n') == NULL)
			{
				ft_clean_vector(BUFFER_SIZE + 1, buf);
				size = read(fd,buf, BUFFER_SIZE);
				if (size > 0)
				{
					ft_add(buf, memory);
				}
			}
		}
	}
	*line = ft_set_next_line(memory);
	ft_clear_memory(ft_strlen(*line) + 1, memory);
	if (size == 0 && memory[0] == 0)
		return (0);
	else
		return (1);
}
