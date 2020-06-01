/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zeros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:53:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/06/01 16:19:06 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_flag_zeros(t_ptf *parms)
{
	int temp;

	temp = 0;
	if (parms->flag[1] == '*')
	{
		temp = va_arg(parms->ap, int);
		if (temp < 0)
		{
			parms->width = -temp;
			ft_check_precision(parms);
			ft_set_conversion(parms);
			ft_padding('r', parms);
		}
		else
		{
			parms->width = temp;
		}
		
	}
	if(temp >= 0)
	{
		if (parms->width == 0)
			ft_get_width(parms, 1);
		ft_check_precision(parms);
		ft_set_conversion(parms);
		if (parms->len_c < (int)parms->width && parms->precision != -1)
		{
			ft_padding('l', parms);
		}
		else
		{
			ft_padding('0', parms);
		}
	}

}