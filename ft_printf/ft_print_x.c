/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:24:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/25 13:50:50 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_x(t_ptf *parms)
{
    parms->v_p = va_arg(parms->ap, void *);
    parms->v_str = ft_itoa_hex((int32_t)parms->v_p, HEX_BASE_L);
    parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);

}
