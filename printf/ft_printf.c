/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:19:33 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 15:25:55 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

static  void    ft_init_pms(t_ptf   *pms, const char *str)
{
	pms->flag = NULL;
    pms->str = (char *)str;
    pms->v_char = (char *)ft_calloc(2, sizeof(char));
    pms->v_int = 0;
	pms->v_ui = 0;
	pms->width = 0;
    pms->minus = 0;
    pms->zero = 0 ;
    pms->point = 0;
    pms->single_l = 0;
    pms->double_l = 0;
    pms->single_h = 0;
    pms->double_h = 0;
    pms->hashtag = 0;
    pms->space = 0;
    pms->plus = 0;
    pms->len = ft_strlen(str);
    pms->slen = ft_strlen(str);
    pms->len_c = 0;
    pms->i = 0;
}

int	ft_printf (const char *str, ...)
{
    t_ptf	pms;

    ft_init_pms(&pms, str);
    va_start(pms.ap, str);

    while (pms.i < pms.slen)
    {
        if (pms.str[pms.i] == '%')
            ft_check_flag(&pms);
        ft_putchar_fd(str[pms.i],1);
        pms.i += 1;
    }
	va_end(pms.ap);
	return (pms.len);
}
