/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:26:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/12 15:57:11 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static  char    ft_hex_notation(size_t n, char ud)
{
    if (n < 10)
    {
        return ('0' + n);
    }
    else
    {
        if (ud == 'u')
        {
            return ('A' + n - 10);
        }
        else
        {
            return ('a' + n - 10);
        }
    }

}

static char    *ft_itoa_aux(size_t nb, char ud)
{   
     size_t q;
     char *resp;
     char *temp;
     
     temp = (char *)ft_calloc(2,sizeof(char));
     q = nb / 16;
     *temp = ft_hex_notation(nb % 16, ud);
     if (q == 0)
     {   
         return(temp);
     }
     else
     {   
         resp = ft_strjoin(ft_itoa_aux(q, ud), temp);
     }   
     return (resp);  
}


 char    *ft_itoa_hex(size_t nb, char ud)
 {
    char *resp;
    char *temp;
    int i;
    int len_temp;

    temp = ft_itoa_aux(nb, ud);
    
    if ((temp[0] == 'f' && temp[1] == 'f' && temp[2] == 'f' && temp[3] == 'f') ||
    (temp[0] == 'F' && temp[1] == 'F' && temp[2] == 'F' && temp[3] == 'F'))
    {
        i = -1;
        len_temp = ft_strlen(temp);
        resp = (char *)ft_calloc(len_temp - 8 + 1, sizeof(char));
        while (++i + 8 < len_temp)
        {
            resp[i] = temp[i + 8];

        }
        return (resp);
    }

    return (temp);
 }
