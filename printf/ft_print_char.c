/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:46:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 19:12:43 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_char(t_ptf *pms)
{
    pms->v_char = va_arg(pms->ap, int);
    // ft_putchar_fd(pms->v_char, 1);

	if (pms->width > 0)
	{
		ft_padding('l', pms->width - ft_strlen(&pms->v_char));
		ft_putchar_fd(pms->v_char, 1);
		pms->len += pms->width - ft_strlen(&pms->v_char) - 2;
	}
	else
	{
		ft_putchar_fd(pms->v_char, 1);
		pms->len += ft_strlen(&pms->v_char) - 1;
	}
    
}