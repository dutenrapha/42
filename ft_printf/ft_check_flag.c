/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/26 17:25:43 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libftprintf.h"

static	void 	ft_check_precision(t_ptf *parms)
{
	int init;
	int final;
	char *pos;
	char *temp;

	temp = NULL;
	pos = NULL;
	pos = ft_strchr(parms->flag,'.');
	if (pos!= NULL)
	{
		if (*(pos + 1) == '*')
		{
			parms->precision = va_arg(parms->ap, int);
		}
		else
		{
			init = 0;
			final = 0;
			init = ft_strlen(parms->flag) - ft_strlen(pos) + 1;
			final = ft_strlen(parms->flag) - ft_strlen(ft_strrchr(parms->flag,parms->conversion));
			temp = ft_substr(parms->flag,init,final - init);
			parms->precision = ft_atoi(temp);
		}
		free(temp);
	}
}

static	void	ft_get_width(t_ptf *parms, int k)
{
	size_t l_flag;
	char *temp;

	temp = NULL;
	l_flag = 0;
	while (!ft_match(parms->flag[l_flag + k], BREAKS))
	{
		l_flag++;
	}
	temp = ft_substr(parms->flag,k,l_flag);
	parms->width = ft_atoi(temp);
	free(temp);
}

static	void	ft_set_conversion(t_ptf *parms)
{
	if (parms->conversion == 'd' || parms->conversion == 'i')
		ft_print_int(parms);
	if (parms->conversion == 'c')
		ft_print_char(parms);
	if (parms->conversion == 's')
		ft_print_str(parms);
	if (parms->conversion == 'x')
		ft_print_x(parms);
	if (parms->conversion == 'X')
		ft_print_xup(parms);
	if (parms->conversion == 'p')
		ft_print_p(parms);
	if (parms->conversion == 'u')
		ft_print_u(parms);
}

static void	ft_get_flag(t_ptf *parms)
{
	size_t l_flag;
	size_t j;

	j = 0;
	l_flag = 1;
	while (!ft_match(parms->str[parms->i + j], CONVERSIONS))
	{
		l_flag++;
		j++;
	}
	if(!(parms->flag = (char *)ft_calloc(l_flag + 1, sizeof(char))))
		return ;
	parms->flag[0] = parms->str[parms->i];
	j = 1;
	while (j < l_flag)
	{
		parms->flag[j] = parms->str[parms->i + j];
		j++;
	}
	parms->conversion = parms->flag[j-1];
	parms->len -= ft_strlen(parms->flag);
	parms->i += ft_strlen(parms->flag);
	if (parms->flag[0] == '*')
	{	
		parms->width = va_arg(parms->ap, int);
	}
	if (parms->flag[0] == '-')
	{
		if (parms->flag[1] == '*')
			parms->width = va_arg(parms->ap, int);
		else
			ft_get_width(parms, 1);
	}
	if (parms->flag[0] == '0')
	{
		if (parms->flag[1] == '*')
			parms->width = va_arg(parms->ap, int);
		else
			ft_get_width(parms, 1);
	}
	ft_check_precision(parms);
}

void	ft_check_flag(t_ptf *parms)
{
    parms->len -= 1;
	parms->i += 1;
	ft_get_flag(parms);
	ft_set_conversion(parms);

	if (parms->precision == 0 && parms->v_str[0] == '0')	
	{
		parms->len -= 1;
	}
	else
	{
		if (ft_match(parms->flag[0], DIGITO))
		{
			if (parms->width == 0)
				ft_get_width(parms, 0);
			ft_padding('l', parms);
		}
		else if (parms->flag[0] == '-')
		{
			ft_padding('r', parms);
		}
		else if (parms->flag[0] == '0')
		{
			ft_padding('0', parms);
		}
		else
		{
			if (parms->conversion == '%')
			{
				parms->len += 1;
				ft_putchar_fd('%', 1);
			}
			else
			{
				ft_putstr_fd(parms->v_str, 1);
			}
		}
	}
}

