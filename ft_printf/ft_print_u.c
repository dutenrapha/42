/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:39:23 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/25 13:11:48 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_u(t_ptf *parms)
{
    parms->v_p = va_arg(parms->ap, void *);
    parms->v_str = ft_itoa_base((unsigned int)parms->v_p, DEC_BASE);
    parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);
}
