/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/18 15:05:19 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libftprintf.h"

static	void 	ft_check_precision(t_ptf *pms)
{
	int init;
	int final;
	char *pos;

	pos = NULL;
	pos = ft_strchr(pms->flag,'.');
	if (pos!= NULL)
	{
		if (*(pos + 1) == '*')
		{
			pms->precision = va_arg(pms->ap, int);
		}
		else
		{
			init = 0;
			final = 0;
			init = ft_strlen(pms->flag) - ft_strlen(pos) + 1;
			final = ft_strlen(pms->flag) - ft_strlen(ft_strrchr(pms->flag,pms->conversion));
			pms->precision = ft_atoi(ft_substr(pms->flag,init,final - init));
		}
	}
}

static	void	ft_get_width(t_ptf *pms, int k)
{
	size_t l_flag;

	l_flag = 0;
	while (!ft_match(pms->flag[l_flag + k], BREAKS))
	{
		l_flag++;
	}
	pms->width = ft_atoi(ft_substr(pms->flag,k,l_flag));
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
	pms->i += ft_strlen(pms->flag);
	if (pms->flag[0] == '*')
	{	
		pms->width = va_arg(pms->ap, int);
	}
	if (pms->flag[0] == '-')
	{
		if (pms->flag[1] == '*')
			pms->width = va_arg(pms->ap, int);
		else
			ft_get_width(pms, 1);
	}
	if (pms->flag[0] == '0')
	{
		if (pms->flag[1] == '*')
			pms->width = va_arg(pms->ap, int);
		else
			ft_get_width(pms, 1);
	}
	ft_check_precision(pms);
}

void	ft_check_flag(t_ptf *pms)
{
    pms->len -= 1;
	pms->i += 1;
	ft_get_flag(pms);
	ft_set_conversion(pms);
	
	if (ft_match(pms->flag[0], DIGITO))
	{
		if (pms->width == 0)
			ft_get_width(pms, 0);
		ft_padding('l', pms);
	}
	else if (pms->flag[0] == '-')
	{
		ft_padding('r', pms);
	}
	else if (pms->flag[0] == '0')
	{
		ft_padding('0', pms);
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

