/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:46:30 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 17:46:48 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_str(t_ptf *pms)
{
     pms->v_str = va_arg(pms->ap, char *);
     ft_putstr_fd(pms->v_str, 1);
     pms->len += ft_strlen(pms->v_str) - 1;
}