/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:52:20 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 17:52:45 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_match(char c, char *conversion)
{
	size_t i;
	size_t len;

	len = ft_strlen(conversion);
	i = 0;
	 while (i < len)
	 {
		 if (c == conversion[i])
			return (1);
		i++;
	 }
	 return (0);
}