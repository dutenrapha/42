/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:45:25 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/26 17:25:59 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_int(t_ptf *parms)
{
	char *temp;
	int diff;
	int i;

	i = 0;
	diff =0;
	temp = NULL;
    parms->v_int = va_arg(parms->ap, int);
	parms->v_str = ft_itoa(parms->v_int);
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


	parms->len += ft_strlen(parms->v_str); 
}


