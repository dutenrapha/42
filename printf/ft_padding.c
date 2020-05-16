/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 18:41:34 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 19:02:25 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_print_padding(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

void ft_padding(char type, t_ptf *pms)
{
	int	size;

	size = 0;
	size = pms->width - pms->len_c;
	// ft_putstr_fd("ZZZ",1);
	// ft_putnbr_fd(pms->width,1);
	// ft_putstr_fd("ZZZ",1);
	if (type == 'l')
	{
		ft_print_padding(size);
		if (size > 0)
			pms->len += pms->width - pms->len_c;
		if (pms->conversion == 'c')
		    ft_putstr_fd(pms->v_char, 1);
	    else
		    ft_putstr_fd(pms->v_str, 1);
	}
	if (type == 'r')
	{
		if (size > 0)
			pms->len += pms->width - pms->len_c;
		if (pms->conversion == 'c')
		    ft_putstr_fd(pms->v_char, 1);
	    else
		    ft_putstr_fd(pms->v_str, 1);
		ft_print_padding(size);
	}
}