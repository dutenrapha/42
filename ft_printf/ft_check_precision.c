/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:57:22 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/29 16:57:46 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 	ft_check_precision(t_ptf *parms)
{
	int init;
	int final;
	char *pos;
	char *temp;

	temp = NULL;
	pos = NULL;
	pos = ft_strchr(parms->flag,'.');
	if (pos!= NULL)
	{
		if (*(pos + 1) == '*')
		{
			parms->precision = va_arg(parms->ap, int);
		}
		else
		{
			init = 0;
			final = 0;
			init = ft_strlen(parms->flag) - ft_strlen(pos) + 1;
			final = ft_strlen(parms->flag) - ft_strlen(ft_strrchr(parms->flag,parms->conversion));
			temp = ft_substr(parms->flag,init,final - init);
			parms->precision = ft_atoi(temp);
		}
		free(temp);
	}
}
