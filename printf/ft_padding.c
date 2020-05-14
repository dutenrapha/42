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

static void ft_print_left_padding(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

void ft_padding(char type, int size)
{
	if (type == 'l')
	{
		ft_print_left_padding(size);
	}
}