/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:46:30 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/18 11:15:55 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_str(t_ptf *pms)
{
    pms->v_str = va_arg(pms->ap, char *);
	pms->len_c = ft_strlen(pms->v_str);
	if (pms->precision < pms->len_c && ft_strchr(pms->flag,'.') != NULL)
	{
		pms->v_str = ft_substr(pms->v_str, 0, pms->precision);
		pms->len_c = ft_strlen(pms->v_str);
	}
	pms->len += ft_strlen(pms->v_str); 
}