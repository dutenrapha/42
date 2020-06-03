/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/06/03 20:22:58 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libftprintf.h"

static	void	ft_set_flag(t_ptf *parms)
{
	if (parms->flag[0] == '*')
		ft_flag_asterisk(parms);
	else if (ft_match(parms->flag[0], DIGITO))
		ft_flag_width(parms);
	else if (parms->flag[0] == '-')
		ft_flag_minus(parms);
	else if (parms->flag[0] == '0')
		ft_flag_zeros(parms);
	else if (parms->flag[0] == '.')
		ft_flag_precision(parms);
	else
	{
		ft_flag_none(parms);
		
	}
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
	if (parms->conversion == 's')
		parms->string = 1;
	parms->len -= ft_strlen(parms->flag);
	parms->i += ft_strlen(parms->flag);
	// if (parms->flag[0] == '*')
	// {	
	// 	parms->asterisk = va_arg(parms->ap, int);
	// 	if (parms->asterisk > 0)
	// 		parms->width = parms->width;
	// 	else
	// 	{
	// 		parms->width = -1*parms->asterisk;
	// 	}
		
	// }
	// if (parms->flag[0] == '-')
	// {
	// 	if (parms->flag[1] == '*')
	// 		parms->width = va_arg(parms->ap, int);
	// 	else
	// 		ft_get_width(parms, 1);
	// }
	// if (parms->flag[0] == '0')
	// {
	// 	if (parms->flag[1] == '*')
	// 		parms->width = va_arg(parms->ap, int);
	// 	else
	// 		ft_get_width(parms, 1);
	// }
	// ft_check_precision(parms);
}

void	ft_check_flag(t_ptf *parms)
{
    parms->len -= 1;
	parms->i += 1;
	ft_get_flag(parms);
	ft_set_flag(parms);

	// ft_set_conversion(parms);
	
	// if (ft_match(parms->flag[0], DIGITO))
	// {
	// 	if (parms->width == 0)
	// 		ft_get_width(parms, 0);
	// 	ft_padding('l', parms);
	// }
	// else if (parms->flag[0] == '-')
	// {
	// 	ft_padding('r', parms);
	// }
	// else if (parms->flag[0] == '0')
	// {
	// 	if (parms->len_c < (int)parms->width)
	// 	{
	// 		ft_padding('l', parms);
	// 	}
	// 	else
	// 	{
	// 		ft_padding('0', parms);
	// 	}
	// }
	// else
	// {
	// 	if (parms->conversion == '%')
	// 	{
	// 		parms->len += 1;
	// 		ft_putchar_fd('%', 1);
	// 	}
	// 	else
	// 	{
	// 		ft_putstr_fd(parms->v_str, 1);
	// 	}
	// }
}

