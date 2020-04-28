/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:36:33 by gadoglio          #+#    #+#             */
/*   Updated: 2020/01/24 18:07:16 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*st;

	i = 0;
	st = (char *)s;
	while (i < n)
	{
		st[i] = '\0';
		i++;
	}
}