/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:39:23 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 19:12:05 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_u(t_ptf *pms)
{
    pms->v_p = va_arg(pms->ap, void *);
    pms->v_str = ft_itoa_base((uintmax_t)pms->v_p, DEC_BASE);
    // ft_putstr_fd(pms->v_str, 1);

	if (pms->width > 0)
	{
		ft_padding('l', pms->width - ft_strlen(pms->v_str));
		ft_putstr_fd(pms->v_str, 1);
		pms->len += pms->width - ft_strlen(pms->v_str) - 1;
	}
	else
	{
		ft_putstr_fd(pms->v_str, 1);
		pms->len += ft_strlen(pms->v_str) - 1;
	}

    

}
