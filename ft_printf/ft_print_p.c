/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:06:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 19:01:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux(t_ptf *parms, char *text)
{
	char	*temp;
	int		diff;
	int		i;

	temp = NULL;
	diff = 0;
	i = 0;
	diff = parms->precision - parms->len_c;
	if (diff > 0)
	{
		temp = ft_strdup(text);
		free(text);
		text = NULL;
		text = (char *)ft_calloc(parms->precision + 1, sizeof(char));
		ft_memset(text, '0', parms->precision);
		while (i < parms->len_c)
		{
			text[diff + i] = temp[i];
			i++;
		}
		free(temp);
		parms->len_c = ft_strlen(text);
	}
}

void	ft_print_p(t_ptf *parms)
{
	char *temp;

	temp = NULL;
	parms->v_p = va_arg(parms->ap, void *);
	temp = ft_itoa_base((intptr_t)parms->v_p, HEX_BASE_L);
	parms->len_c = ft_strlen(temp);
	ft_aux(parms, temp);
	if (*temp == '0' && parms->precision == 0)
		parms->v_str = ft_strjoin("0x", "");
	else
	{
		parms->v_str = ft_strjoin("0x", temp);
	}
	free(temp);
	parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);
}
