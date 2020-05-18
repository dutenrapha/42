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
    pms->len_c = ft_strlen(pms->v_str);
	pms->len += ft_strlen(pms->v_str);
}
