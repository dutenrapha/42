/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:45:16 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 17:44:10 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_match(char c, char *conversion)
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


static	void	ft_get_width(t_ptf *pms)
{
	size_t l_flag;

	l_flag = 0;
	while (!ft_match(pms->flag[l_flag], FLAG_BREAKS))
	{
		l_flag++;
	}

	pms->width = ft_atoi(ft_substr(pms->flag,0,l_flag));

	ft_putstr_fd("ZZZZ", 1);
	ft_putnbr_fd(pms->width, 1);
	ft_putstr_fd("ZZZZ", 1);
}

void	ft_flag_apply(t_ptf *pms)
{
	if (ft_isdigit(pms->flag[0]))
	{
		ft_get_width(pms);
	}
	
	if (pms->conversion == 'd' || pms->conversion == 'i')
		ft_print_int(pms);
	if (pms->conversion == 'c')
		ft_print_char(pms);
	if (pms->conversion == 's')
		ft_print_str(pms);
	if (pms->conversion == 'x')
		ft_print_x(pms);
	if (pms->conversion == 'X')
		ft_print_xup(pms);
	if (pms->conversion == 'p')
		ft_print_p(pms);
	if (pms->conversion == 'u')
		ft_print_u(pms);

}