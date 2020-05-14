/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:45:25 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 19:13:02 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_int(t_ptf *pms)
{
    pms->v_int = va_arg(pms->ap, int);
	if (pms->width > 0)
	{
		ft_padding('l', pms->width - ft_int_len(pms->v_int));
		ft_putnbr_fd(pms->v_int, 1);
		pms->len += pms->width - ft_int_len(pms->v_int) - 1;
	}
	else
	{
		ft_putnbr_fd(pms->v_int, 1);
		pms->len += ft_int_len(pms->v_int) - 1;
	}
    
}


