/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/12 17:20:44 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include    "libftprintf.h"

static  void ft_print_int(t_ptf *pms)
{
    pms->v_int = va_arg(pms->ap, int);
    ft_putnbr_fd(pms->v_int, 1);
    pms->len += ft_int_len(pms->v_int) - 1;
}

static  void ft_print_char(t_ptf *pms)
{
    pms->v_char = va_arg(pms->ap, int);
    ft_putchar_fd(pms->v_char, 1);
    pms->len += ft_strlen(&pms->v_char) - 1;
}

static  void ft_print_str(t_ptf *pms)
{
     pms->v_str = va_arg(pms->ap, char *);
     ft_putstr_fd(pms->v_str, 1);
     pms->len += ft_strlen(pms->v_str) - 1;
}

void	ft_check_flag(t_ptf *pms)
{
    pms->len -= 1;
    pms->i += 1;
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
    pms->i += 1;
}
