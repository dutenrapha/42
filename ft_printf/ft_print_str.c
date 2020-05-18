/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:46:30 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/18 14:57:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_str(t_ptf *pms)
{
	char *temp;

	temp = NULL;
    
	pms->v_str = va_arg(pms->ap, char *);
	pms->len_c = ft_strlen(pms->v_str);
	if (pms->precision < pms->len_c && ft_strchr(pms->flag,'.') != NULL)
	{
		temp =  ft_strdup(pms->v_str);
		free(pms->v_str);
		pms->v_str = NULL;
		pms->v_str = ft_substr(temp, 0, pms->precision);
		free(temp);
		pms->len_c = ft_strlen(pms->v_str);
	}
	pms->len += ft_strlen(pms->v_str); 
}