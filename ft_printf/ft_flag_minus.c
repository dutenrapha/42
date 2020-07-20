/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:50:48 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/20 13:51:19 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_flag_minus(t_ptf *parms)
{
	int temp;
	int d;
	char *asterisk;
	char *precision;
	
	temp = 0;
	d = 0;
	asterisk = NULL;
	precision = NULL;
	asterisk = ft_strchr(parms->flag, '*');
	precision = ft_strchr(parms->flag, '.');
	if (asterisk != NULL && precision != NULL)
		d = ft_strlen(asterisk) - ft_strlen(precision);

	if (parms->v_ast == 0 && asterisk != NULL && d >=0)
	{
		temp = va_arg(parms->ap, int);
		if (temp <0)
			parms->width = -temp;
		else
		parms->width = temp;
	}

	
	if (parms->width == 0)
		ft_get_width(parms, 1);
	ft_check_precision(parms);
	ft_set_conversion(parms);
	ft_padding('r', parms);
}