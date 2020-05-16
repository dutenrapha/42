/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 18:57:55 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libftprintf.h"

static	void	ft_get_width(t_ptf *pms, int k)
{
	size_t l_flag;

	l_flag = 0;
	while (!ft_match(pms->flag[l_flag + k], BREAKS))
	{
		l_flag++;
	}
	pms->width = ft_atoi(ft_substr(pms->flag,1,l_flag));
	pms->i += l_flag;
}

static	void	ft_set_conversion(t_ptf *pms)
{
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
	pms->i += 1;
}

static void	ft_get_flag(t_ptf *pms)
{
	size_t l_flag;
	size_t j;

	j = 0;
	l_flag = 1;
	while (!ft_match(pms->str[pms->i + j], CONVERSIONS))
	{
		l_flag++;
		j++;
	}
	if(!(pms->flag = (char *)ft_calloc(l_flag + 1, sizeof(char))))
		return ;
	pms->flag[0] = pms->str[pms->i];
	j = 1;
	while (j < l_flag)
	{
		pms->flag[j] = pms->str[pms->i + j];
		j++;
	}
	pms->conversion = pms->flag[j-1];
	pms->len -= ft_strlen(pms->flag);
}

void	ft_check_flag(t_ptf *pms)
{
    pms->len -= 1;
	pms->i += 1;
	ft_get_flag(pms);
	ft_set_conversion(pms);
	// ft_putstr_fd("ZZZ",1);
	// ft_putchar_fd(pms->conversion,1);
	// ft_putstr_fd("ZZZ",1);
	if (ft_isdigit(pms->flag[0]))
	{
		ft_get_width(pms, 0);
		ft_padding('l', pms);
	}
	else if (pms->flag[0] == '-')
	{
		pms->i += 1;
		ft_get_width(pms, 1);
		ft_padding('r', pms);
	}
	else
	{
		if (pms->conversion == '%')
			ft_putchar_fd('%', 1);
		else if (pms->conversion == 'c')
		    ft_putstr_fd(pms->v_char, 1);
	    else
		    ft_putstr_fd(pms->v_str, 1);
	}
}

