/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:21:35 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/12 16:14:22 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_params
{
	va_list		ap;
	char		*str;
	char		*v_str;
	char		v_char;
	int			v_int;
	int			minus;
	int			zero;
	int			point;
	int			single_l;
	int			double_l;
	int			single_h;
	int			double_h;
	int			hashtag;
	int			space;
	int			plus;
	int			len;
	int			slen;
	int 		i;
}				t_ptf;


int		ft_printf(const char *str, ...);
void	ft_check_flag(t_ptf *pms);
int		ft_int_len(int d);
void	ft_print_x(t_ptf *pms);
char	*ft_itoa_hex(size_t nb, char ud);
void	ft_print_X(t_ptf *pms);
void	ft_print_p(t_ptf *pms);

#endif
