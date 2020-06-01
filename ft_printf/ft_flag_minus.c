/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:50:48 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/29 17:00:41 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_flag_minus(t_ptf *parms)
{
	if (parms->flag[1] == '*')
		parms->width = va_arg(parms->ap, int);

	if (parms->width == 0)
		ft_get_width(parms, 1);
	ft_check_precision(parms);
	ft_set_conversion(parms);
	ft_padding('r', parms);
}