/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:52:20 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 11:34:05 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_match(char c, char *conversion)
{
	int i;
		
	i = 0;
	while (conversion[i] != '\0')
	{
		if (c == conversion[i])
			return (1);
		i++;
	}
	return (0);
}
