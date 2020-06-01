/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zeros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:53:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/06/01 12:44:30 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_flag_zeros(t_ptf *parms)
{
	if (parms->flag[1] == '*')
		parms->width = va_arg(parms->ap, int);
	if (parms->width == 0)
		ft_get_width(parms, 1);
	ft_check_precision(parms);
	ft_set_conversion(parms);
	if (parms->len_c < (int)parms->width)
	{
		ft_padding('l', parms);
	}
	else
	{
		ft_padding('0', parms);
	}
}