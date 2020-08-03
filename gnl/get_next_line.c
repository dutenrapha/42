/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:43:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/03 15:47:28 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_break(char *buf, char **before, char **after)
{
	int		len_before;
	int		len_after;
	int		i;
	int		j;
	
	len_before = 0;
	i = 0;
	j = 0;
	while (buf[len_before] != '\n')
		len_before++;

	if (len_before != 0)
	{
		*before = (char *)malloc((len_before + 1) * sizeof(char));
		before[len_before] = '\0';
		while (buf[i] != '\n')
		{
			(*before)[i] = buf[i];
			i++;
		}
	}
	
	len_before++;
	len_after  = 0;
	while (buf[len_before + len_after] != '\0')
		len_after++;
	if (len_after != 0)
	{
		*after = (char *)malloc((len_after + 1) * sizeof(char));
		after[len_after] = '\0';
		while (buf[++i] != '\0')
		{
			(*after)[j] = buf[i];
			j++;
		}
	}

}

int			get_next_line(int fd, char **line)
{
	int		size;
	char	buf[BUFFER_SIZE + 1];
	// static char 	*memory[INT_MAX];
	char	*breakline;
	char	*temp;
	char	*before;
	char	*after;

	before = NULL;
	after = NULL;
	breakline = NULL;
	temp = NULL;
	size = read(fd, buf, BUFFER_SIZE);
	*line = ft_strdup(buf);
	while (breakline == NULL)
	{
		size = read(fd, buf, BUFFER_SIZE);
		breakline = ft_strchr(buf, '\n');
		if (breakline != NULL)
		{
			ft_break(buf, &before, &after);
			printf("resto %s\n", after);
			
			if (before != NULL)
			{
				temp = ft_strjoin(*line, before);
				free(*line);
				*line = ft_strdup(temp);
				free(temp);
			}
			size = ft_strlen(*line);
			return (size);
		}
		else
		{
			temp = ft_strjoin(*line, buf);
		}
		free(*line);
		*line = ft_strdup(temp);
		free(temp);
	}
	return (size);
}