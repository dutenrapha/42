/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:21:35 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 17:47:17 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

# define DEC_BASE	"0123456789"
# define HEX_BASE_L	"0123456789abcdef"
# define HEX_BASE_U	"0123456789ABCDEF"
# define CONVERSIONS	"cspdiuxX%"
# define FLAG_BREAKS	".*cspdiuxX%"

typedef struct	s_params
{
	va_list		ap;
	char		*flag;
	char		*str;
	char		*v_str;
	char		v_char;
	intmax_t	v_int;
	void		*v_p;
	uintmax_t v_ui;
	char		conversion;
	int			width;
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
int		ft_int_len(intmax_t d);
void	ft_print_x(t_ptf *pms);
char	*ft_itoa_base(uintmax_t nb, char* base);
void	ft_print_xup(t_ptf *pms);
void	ft_print_p(t_ptf *pms);
void	ft_print_u(t_ptf *pms);
void	ft_flag_apply(t_ptf *pms);
void ft_print_int(t_ptf *pms);
void ft_print_char(t_ptf *pms);
void ft_print_str(t_ptf *pms);

#endif
