/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:47:14 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/21 19:42:46 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_print_xup(t_ptf *parms)
{
    parms->v_p = va_arg(parms->ap, void *);
    parms->v_str = ft_itoa_base((intmax_t)parms->v_p, HEX_BASE_U);
    parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);
}


    
