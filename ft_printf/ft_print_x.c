/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:24:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/06/04 20:45:33 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_x(t_ptf *parms)
{
	char *temp;
	int diff;
	int i;

	i = 0;
	diff =0;
	temp = NULL;
    parms->v_p = va_arg(parms->ap, void *);
    parms->v_str = ft_itoa_hex((int32_t)parms->v_p, HEX_BASE_L);
    parms->len_c = ft_strlen(parms->v_str);
	diff = parms->precision - parms->len_c;
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
	if (parms->v_str[0] == '0' && parms->precision < parms->len_c && parms->precision >= 0)
	{
		temp =  ft_strdup(parms->v_str);
		free(parms->v_str);
		parms->v_str = NULL;
		parms->v_str = ft_substr(temp, 0, parms->precision);
		free(temp);
		parms->len_c = ft_strlen(parms->v_str);
	}		
	parms->len += ft_strlen(parms->v_str);
}
