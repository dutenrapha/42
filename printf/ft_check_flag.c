/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 17:46:41 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include    "libftprintf.h"

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
	pms->conversion = pms->flag[j];
}

void	ft_check_flag(t_ptf *pms)
{
    pms->len -= 1;
	pms->i += 1;
	ft_get_flag(pms);

	if (ft_isdigit(pms->str[pms->i]))
	{
		ft_flag_apply(pms);
		pms->i += 1;
	}
	else
	{
		if (pms->str[pms->i] == '%')
			ft_putchar_fd(pms->str[pms->i], 1);
		if (pms->str[pms->i] == 'd' || pms->str[pms->i] == 'i')
			ft_print_int(pms);
		if (pms->str[pms->i] == 'c')
			ft_print_char(pms);
		if (pms->str[pms->i] == 's')
			ft_print_str(pms);
		if (pms->str[pms->i] == 'x')
			ft_print_x(pms);
		if (pms->str[pms->i] == 'X')
			ft_print_xup(pms);
		if (pms->str[pms->i] == 'p')
			ft_print_p(pms);
		if (pms->str[pms->i] == 'u')
			ft_print_u(pms);
		pms->i += 1;
	}
}

