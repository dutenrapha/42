/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:46:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/20 15:02:30 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_char(t_ptf *parms)
{
	char *temp;

	temp = NULL;
	if(!(temp = (char *)ft_calloc(2,sizeof(char))))
		return ;
	parms->v_c = va_arg(parms->ap, int);
	temp[0] = (char)parms->v_c;
	parms->v_str = ft_strdup(temp);
	free(temp);
	parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);
}