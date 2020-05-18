/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:19:33 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/18 15:03:03 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

static void		ft_reset(t_ptf *pms)
{
	pms->flag = NULL;
	pms->v_str = NULL;
    pms->v_char = (char *)ft_calloc(2, sizeof(char));
	pms->v_p = NULL;
    pms->v_int = 0;
	pms->v_ui = 0;
	pms->conversion = '\0';
	pms->width = 0;
    pms->precision = 0;
}

static  void    ft_init_pms(t_ptf   *pms, const char *str)
{
	pms->len_c = 0;
	pms->flag = NULL;
    pms->str = (char *)str;
	pms->v_str = NULL;
    pms->v_char = (char *)ft_calloc(2, sizeof(char));
	pms->v_p = NULL;
    pms->v_int = 0;
	pms->v_ui = 0;
	pms->conversion = '\0';
	pms->width = 0;
    pms->precision = 0;
    // pms->single_l = 0;
    // pms->double_l = 0;
    // pms->single_h = 0;
    // pms->double_h = 0;
    // pms->hashtag = 0;
    // pms->space = 0;
    // pms->plus = 0;
    pms->len = ft_strlen(str);
    pms->slen = ft_strlen(str);
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
			ft_reset(&pms);
        ft_putchar_fd(str[pms.i],1);
        pms.i += 1;
    }
	va_end(pms.ap);
	free(pms.v_char);
	return (pms.len);
}