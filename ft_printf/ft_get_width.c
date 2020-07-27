/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:49:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 14:14:49 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_flag(t_ptf *parms)
{
	int i;
	int j;
	int end;
	
	end = 0;
	j = 0;
	while (1)
	{
		i = 0;
		while (BREAKS[i] != '\0' && end == 0)
		{
			if (parms->str[parms->i + j] == BREAKS[i])
				end = 1;
			i++;
		}
		j++;
		if (end == 1)
			break;
	}
	return (j);
}



void	ft_get_width(t_ptf *parms, int k)
{
	size_t	l_flag;
	char	*temp;

	temp = NULL;
	l_flag = 0;
	// while (!ft_match(parms->flag[l_flag + k], BREAKS))
	// {
	// 	l_flag++;
	// }
	l_flag = ft_len_flag(parms);
	temp = ft_substr(parms->flag, k, l_flag);
	parms->width = ft_atoi(temp);
	free(temp);
}
