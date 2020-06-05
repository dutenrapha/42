/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_none.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:54:45 by rdutenke          #+#    #+#             */
/*   Updated: 2020/06/05 16:00:28 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_flag_none(t_ptf *parms)
{
	if (parms->conversion == '%')
	{
		parms->len += 1;
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_set_conversion(parms);
		ft_putstr_fd(parms->v_str, 1);
	}
	if (parms->conversion == 'c' && parms->v_str[0] == '\0')
		parms->len +=1;	
}