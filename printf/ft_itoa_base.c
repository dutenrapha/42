/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:26:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/11 21:10:56 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base(size_t nb, int base)
{
    char *resp; 
    size_t  temp;
    int len;

    len = ft_int_len(nb);
    resp = (char *)malloc((len + 1)*sizeof(char));
    while (nb != 0)
    {
        temp = 0;
        temp = nb % base;
        if (temp < 10)
        {
            *resp = temp + 48;
            resp++;
        }
        else
        {
            *resp = temp + 55;
            resp++;
        }
        nb = nb / base;
    }

    return (resp);
}
