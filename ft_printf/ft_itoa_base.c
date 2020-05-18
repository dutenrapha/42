/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:26:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/18 14:16:22 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char    *ft_itoa_aux(uintmax_t nb, char* base, size_t b_len)
{   
     uintmax_t q;
     char *resp;
     char *temp;
	
	 resp = NULL;
	 temp = NULL;
	 q = 0;
	 temp = (char *)ft_calloc(2,sizeof(char));
     q = nb / b_len;
	 *temp = base[nb % b_len];
     if (q == 0)
     {   
         return(temp);
     }
     else
     {   
         resp = ft_strjoin(ft_itoa_aux(q, base, b_len), temp);
     }   
	 free(temp);
     return (resp);  
}


 char    *ft_itoa_base(uintmax_t nb, char* base)
 {
    char *temp;
	size_t b_len;
	 
	b_len = ft_strlen(base);
    temp = ft_itoa_aux(nb, base, b_len);
    return (temp);
 }
