/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:49:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/29 15:49:49 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_width(t_ptf *parms, int k)
{
	size_t l_flag;
	char *temp;

	temp = NULL;
	l_flag = 0;
	while (!ft_match(parms->flag[l_flag + k], BREAKS))
	{
		l_flag++;
	}
	temp = ft_substr(parms->flag,k,l_flag);
	parms->width = ft_atoi(temp);
	free(temp);
}