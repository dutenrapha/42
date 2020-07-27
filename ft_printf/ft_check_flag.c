/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 14:13:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_set_flag(t_ptf *parms)
{
	if (parms->flag[0] == '*')
		ft_flag_asterisk(parms);
	else if (ft_isdigit(parms->flag[0]))
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

static int	ft_len_flag(t_ptf *parms)
{
	int i;
	int j;
	int end;
	
	end = 0;
	j = 0;
	while (1)
	{
		i = 0;
		while (CONVERSIONS[i] != '\0' && end == 0)
		{
			if (parms->str[parms->i + j] == CONVERSIONS[i])
				end = 1;
			i++;
		}
		j++;
		if (end == 1)
			break;
	}
	return (j);
}


static void		ft_get_flag(t_ptf *parms)
{
	size_t l_flag;
	size_t j;

	j = 0;
	l_flag = 0;
	// while (!ft_match(parms->str[parms->i + j], CONVERSIONS))
	// {
	// 	l_flag++;
	// 	j++;
	// }
	l_flag = ft_len_flag(parms);

	if (!(parms->flag = (char *)ft_calloc(l_flag + 1, sizeof(char))))
		return ;
	parms->flag[0] = parms->str[parms->i];
	j = 1;
	while (j < l_flag)
	{
		parms->flag[j] = parms->str[parms->i + j];
		j++;
	}
	parms->conversion = parms->flag[j - 1];
	parms->len -= ft_strlen(parms->flag);
	parms->i += ft_strlen(parms->flag);
}

void			ft_check_flag(t_ptf *parms)
{
	parms->len -= 1;
	parms->i += 1;
	ft_get_flag(parms);
	ft_set_flag(parms);
}
