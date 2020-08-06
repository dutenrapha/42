/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:08:45 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/06 16:03:22 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	line = NULL;
	fd = 0;
	fd =  open("1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo");
	}

	size = get_next_line(fd, &line);
	if (size > 0)
	{
		printf("A primeira linha  é \"%s\" e tem %i caracteres\n", line, size);
		free(line);
	}
	size = get_next_line(fd, &line);
	if (size > 0)
	{
		printf("A segunda linha  é \"%s\" e tem %i caracteres\n", line, size);
		free(line);
	}
	size = get_next_line(fd, &line);
	if (size > 0)
	{
		printf("A terceira linha  é \"%s\" e tem %i caracteres\n\n", line, size);
		free(line);
	}
	size = get_next_line(fd, &line);
	if (size > 0)
	{
		printf("A quarta linha  é \"%s\" e tem %i caracteres\n\n", line, size);
		free(line);
	}
	return (0);
}