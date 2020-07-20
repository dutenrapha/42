/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:50:48 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/20 08:56:47 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_flag_minus(t_ptf *parms)
{
	int temp;
	char *pos;
	char *pre;
	
	temp = 0;
	pre = ft_strchr(parms->flag,'.');
	pos = ft_strchr(parms->flag,'*');
	if(pos != NULL)
	{
		if (*pos == '*' && pre == NULL)
		{
			temp = va_arg(parms->ap, void *);
			if (temp <0)
				parms->width = -temp;
			else
			parms->width = temp;
		}
	}
	
	if (parms->width == 0)
		ft_get_width(parms, 1);
	ft_check_precision(parms);
	ft_set_conversion(parms);
	ft_padding('r', parms);
}