/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:21:56 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 23:27:03 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*itoa;
	long int	n_orig;
	int			resto;
	int			i;
	int			passo;

	passo = 0;
	n_orig = n;
	i = -1;
	resto = 1;
	while (resto != 0 || n != 0)
	{
		resto = n % 10;
		n = n / 10;
		i++;
	}
	if (i == 0)
	{
		i++;
		itoa = (char *)ft_calloc(i + 1, sizeof(char));
		if (!itoa)
			return (NULL);
		*(itoa) = 48;
	}
	if (n_orig < 0)
	{
		itoa = (char *)ft_calloc(i + 2, sizeof(char));
		if (!itoa)
			return (NULL);
		*itoa = '-';
		n_orig = -1 * n_orig;
		passo = 0;
	}
	else if (n_orig != 0)
	{
		itoa = (char *)ft_calloc(i + 1, sizeof(char));
		if (!itoa)
			return (NULL);
		passo = -1;
	}
	n = n_orig;
	while (n_orig != 0)
	{
		resto = n_orig % 10;
		n_orig = n_orig / 10;
		*(itoa + i + passo) = resto + 48;
		i--;
	}
	return (itoa);
}
