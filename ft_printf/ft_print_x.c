/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:24:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/21 19:44:03 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_x(t_ptf *parms)
{
    parms->v_p = va_arg(parms->ap, void *);
    parms->v_str = ft_itoa_base((intmax_t)parms->v_p, HEX_BASE_L);
    parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);

}
