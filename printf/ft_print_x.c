/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:24:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 11:14:17 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_x(t_ptf *pms)
{
    pms->v_p = va_arg(pms->ap, void *);
    pms->v_str = ft_itoa_base((uintmax_t)pms->v_p, HEX_BASE_L);
    ft_putstr_fd(pms->v_str, 1);
    pms->len += ft_strlen(pms->v_str) - 1;
}
