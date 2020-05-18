/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:06:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 19:11:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_print_p(t_ptf *pms)
{
    pms->v_p = va_arg(pms->ap, void *);
    pms->v_str = ft_strjoin("0x", ft_itoa_base((uintmax_t)pms->v_p, HEX_BASE_L));
    pms->len_c = ft_strlen(pms->v_str);
	pms->len += ft_strlen(pms->v_str);
}

