/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:43:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/05 21:42:49 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_aux(char *buf)
{
	int		len;
	int		i;
	char	*resp;

	len = 0;
	i = 0;
	resp = NULL;
	while (buf[len] != '\n')
		len++;
	resp = (char *)malloc((len + 1)*sizeof(char));
	resp[len] = '\0';
	while (i < len)
	{
		resp[i] = buf[i];
		i++;
	}
	return (resp);
}

static char	*ft_large_buffer(char *buf)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	line = NULL;
	while (buf[len] != '\n')
		len++;
	line = (char *)malloc((len + 1)*sizeof(char));
	line[len] = '\0';
	while (i < len)
	{
		line[i] = buf[i];
		i++;
	}
	return (line);
}

static char	*ft_small_buffer(int fd, char *buf, char **memory)
{
	char	*temp;
	char	*line;
	int		size;

	size = 0;
	line = NULL;
	temp = NULL;
	line = ft_strdup(buf);
	size = read(fd, buf, BUFFER_SIZE);
	while(ft_strchr(buf, '\n') == NULL && size)
	{
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, buf);
		free(temp);
		size = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n') != NULL)
			break;
	}
	if (buf[0] == '\n')
	{
		if (ft_strlen(buf) != 1)
		{
			*memory = ft_substr(buf, 1, ft_strlen(buf));
		}
	}
	else if (buf[BUFFER_SIZE] == '\n')
	{
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, ft_substr(buf, 0, ft_strlen(buf) - 1));
		free(temp);
	}
	else
	{
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, ft_aux(buf));
		free(temp);
	}
	return (line);
}

int			get_next_line(int fd, char **line)
{
	int				size;
	char			buf[BUFFER_SIZE + 1];
	static char	*memory[INT_MAX];
	// static char 	*memory[10000000];

	size = read(fd, buf, BUFFER_SIZE);
	if (ft_strchr(buf, '\n') != NULL)
	{
		// *line = ft_large_buffer(fd, &buf, &memory);
		*line = ft_large_buffer(buf);
	}
	else
	{
		*line = ft_small_buffer(fd, buf, &*memory);
	}
	size = ft_strlen(*line);
	return (size);
}