/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lia <Lia@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 15:20:43 by Lia               #+#    #+#             */
/*   Updated: 2020/03/31 17:35:00 by Lia              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		find_char(char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		count_args(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}


typedef void(*fptrprintf)(char *);

void ft_printf_int(char *elemento)
{
        ft_putnbr_fd(ft_atoi((const char*)elemento), 1);
}


void ft_printf_str(char *elemento)
{
    ft_putstr_fd(elemento, 1);
}


void ft_printf_final(fptrprintf printf, char *elemento)
{
	
	//Tratamento dos espaços
	printf(elemento);
}

int ft_printf(const char *str, ...)
{
	int	num_args;
	int	i;
	int	index;
	int	start;
	char	*elemento;
	va_list	ap;

	//Conta o número de variávies que devem ser impressas
	num_args = count_args((char *)str, '%');
	va_start(ap, str);
	i = 0;
	start = 0;
	while (i <= num_args)
	{

		//Encontra a posição o próximo do próximo elelemento formatado da string str a ser impresso
		index = find_char(ft_substr(str, 0, ft_strlen(str)), '%');

		//Quando não houver mais elementos formatados para serem impressos deve-se imprimir o restante a string
		if (index == -1)
			index = ft_strlen(str); 

		/*Quando i = 0 imprime tudo que vem antes do primeiro elemento formatado a ser impresso
		Quando i=num_args imprime tudo o que vem depois do último elelemto formatado que foi impresso
		Quando  0 < i < num_args a string intermediária entre o o útimo elemento formatado impresso e o próximo a ser impresso*/
		ft_putstr_fd(ft_substr(str, 0, index), 1);

		//Descobrir qual tipo de formatação o elemento terá
		if (str[index + 1] == 'd')
		{
			elemento = ft_itoa(va_arg(ap, int));
			ft_printf_final(ft_printf_int, elemento);
		}
		else if (str[index + 1] == 's')
		{
			elemento = va_arg(ap, char*);
			ft_printf_final(ft_printf_str, elemento);
		}
	
		i++;
		str = ft_substr(str, index + 2, ft_strlen(str));
	}
	va_end(ap);
	return(0);

}
