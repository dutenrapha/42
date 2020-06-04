/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:47:14 by rdutenke          #+#    #+#             */
/*   Updated: 2020/06/04 17:51:06 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_print_xup(t_ptf *parms)
{
	char *temp;
	int diff;
	int i;

	i = 0;
	diff =0;
	temp = NULL;
    parms->v_p = va_arg(parms->ap, void *);
    parms->v_str = ft_itoa_hex((int32_t)parms->v_p, HEX_BASE_U);
    parms->len_c = ft_strlen(parms->v_str);
	diff = parms->precision - parms->len_c ;
	
	if (diff > 0)
	{

		temp =  ft_strdup(parms->v_str);
		free(parms->v_str);
		parms->v_str = NULL;
		parms->v_str = (char *)ft_calloc(parms->precision + 1 ,sizeof(char));
		ft_memset(parms->v_str, '0', parms->precision);
		while (i < parms->len_c)
		{
			parms->v_str[diff + i] = temp[i];
			i++;
		}
		free(temp);
		parms->len_c = ft_strlen(parms->v_str);
	}
	if(parms->precision == 0 && parms->v_str[0] == '0')
		parms->v_str = ft_strdup(" ");
	parms->len += ft_strlen(parms->v_str);
}


    
