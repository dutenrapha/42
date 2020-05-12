/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:51:30 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/11 15:51:53 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_int_len(int d)
 {
     int int_len;
     int q;
 
     q = d;
     int_len = 0;
 
     while (q != 0)
     {
         q = q / 10;
         int_len++;
     }
 
     return (int_len);
 }
