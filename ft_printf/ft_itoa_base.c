/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:26:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/20 18:31:52 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char    *ft_itoa_aux(uintmax_t nb, char* base, size_t b_len)
{
	uintmax_t q;
	char *resp;
	char *temp;
	char *temp2;
	
	resp = NULL;
	temp = NULL;
	temp2 = NULL;
	q = 0;
	if(!(temp = (char *)ft_calloc(2,sizeof(char))))
		return (NULL);
	q = nb / b_len;
	*temp = base[nb % b_len];
	if (q == 0)
	{
		return(temp);
	}
	else
	{
		temp2 = ft_itoa_aux(q, base, b_len);
		resp = ft_strjoin(temp2, temp);
		free(temp2);
	}
	free(temp);
	return (resp);
}


char *ft_itoa_base(uintmax_t nb, char* base)
{
	char *temp;
	size_t b_len;
	
	temp  = NULL;
	b_len = 0;
	b_len = ft_strlen(base);
	temp = ft_itoa_aux(nb, base, b_len);
	return (temp);
 }
