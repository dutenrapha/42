/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:43:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/31 22:24:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_break(char *buf)
{
	int		len_break;
	int		len_buf;
	char	*resp;

	resp = NULL;
	len_buf = 0;
	len_buf = ft_strlen(buf);
	len_break = 0;
	while (buf[len_break] != '\n')
		len_break++;
	resp = (char *)malloc((len_break + 1)*sizeof(char));
	resp[len_break] = '\0';
	printf("len_buf = %i, len_break = %i\n", len_buf, len_break);
	return (buf);
}

int			get_next_line(int fd, char **line)
{
	int		size;
	char	buf[BUFFER_SIZE + 1];
	char	*breakline;
	char	*temp;
	char	*rest;

	rest = NULL;
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
			rest = ft_break(buf);
			printf("resto %s\n", rest);
			temp = ft_strjoin(*line, buf);
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