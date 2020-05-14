/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:47:14 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 11:25:39 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_print_xup(t_ptf *pms)
{
    pms->v_p = va_arg(pms->ap, void *);
    pms->v_str = ft_itoa_base((uintmax_t)pms->v_p, HEX_BASE_U);
    ft_putstr_fd(pms->v_str, 1);
    pms->len += ft_strlen(pms->v_str) - 1;
}
