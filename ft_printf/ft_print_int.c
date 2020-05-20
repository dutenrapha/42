/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:45:25 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/20 10:58:11 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_int(t_ptf *parms)
{
    parms->v_int = va_arg(parms->ap, int);
	parms->v_str = ft_itoa(parms->v_int);
	parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str); 
}


