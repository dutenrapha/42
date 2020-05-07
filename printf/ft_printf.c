/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:19:33 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/06 22:10:28 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

int	ft_printf(const char *str, ...)
{
	t_ptf	pms;

	va_start(pms.ap, str);

	ft_putstr_fd((char *)str, 1);
    
	va_end(pms.ap);

	return (0);
}
