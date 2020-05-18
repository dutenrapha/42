/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:45:25 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 19:13:02 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_int(t_ptf *pms)
{
    pms->v_int = va_arg(pms->ap, int);
	pms->v_str = ft_itoa(pms->v_int);
	pms->len_c = ft_strlen(pms->v_str);
	pms->len += ft_strlen(pms->v_str); 
}


