/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:06:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 17:24:28 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(t_ptf *parms)
{
	char *temp;

	temp = NULL;
	parms->v_p = va_arg(parms->ap, void *);
	temp = ft_itoa_base((intptr_t)parms->v_p, HEX_BASE_L);
	if (*temp != '0')
		parms->v_str = ft_strjoin("0x", temp);
	else
	{
		parms->v_str = ft_strjoin("0x", "");
	}
	
	free(temp);
	parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);
}
