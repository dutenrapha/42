/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:45:25 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 17:45:50 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_int(t_ptf *pms)
{
    pms->v_int = va_arg(pms->ap, int);
    ft_putnbr_fd(pms->v_int, 1);
    pms->len += ft_int_len(pms->v_int) - 1;
}