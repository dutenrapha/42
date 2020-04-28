/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:18:28 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 16:25:07 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_return(int sinal)
{
	if (sinal == 1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sinal;
	long int	unidade;

	i = 0;
	sinal = 1;
	unidade = 0;
	while (*(nptr + i) == ' ' || *(nptr + i) == '\n' ||
	*(nptr + i) == '\t' || *(nptr + i) == '\v' ||
	*(nptr + i) == '\f' || *(nptr + i) == '\r')
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sinal = -1;
		i += 1;
	}
	while (*(nptr + i) >= 48 && *(nptr + i) <= 57)
	{
		unidade = unidade * 10 + *(nptr + i) - 48;
		if (unidade > 2147483648)
			return (ft_return(sinal));
		i++;
	}
	return (unidade * sinal);
}
