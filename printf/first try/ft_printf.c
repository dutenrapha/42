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

int ft_printf(const char *str, ...)
{
	int	num_args;
	int	i;
	int	index;
	int	start;
	int	num;
	char	*string;
	va_list	ap;

	num_args = count_args((char *)str, '%');
	va_start(ap, str);
	i = 0;
	start = 0;
	while (i <= num_args)
	{
		index = find_char(ft_substr(str, 0, ft_strlen(str)), '%');
		if (index == -1)
			index = ft_strlen(str); 
		ft_putstr_fd(ft_substr(str, 0, index), 1);
		if (str[index + 1] == 'd')
		{
			num = va_arg(ap, int);
			ft_putnbr_fd(num, 1);
		}
		else if (str[index + 1] == 's')
		{
			string = va_arg(ap, char*);
			ft_putstr_fd(string, 1);
		}
		i++;
		str = ft_substr(str, index + 2, ft_strlen(str));
	}
	va_end(ap);
	return(0);

}