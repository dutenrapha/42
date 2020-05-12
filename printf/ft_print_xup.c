/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:47:14 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/12 17:21:18 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_print_xup(t_ptf *pms)
{
    pms->v_int = va_arg(pms->ap, size_t);
    pms->v_str = ft_itoa_hex(pms->v_int, 'u');
    ft_putstr_fd(pms->v_str, 1);
    pms->len += ft_strlen(pms->v_str) - 1;
}
