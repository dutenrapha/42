/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:21:35 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/20 13:48:14 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

# define DIGITO	"*123456789"
# define DEC_BASE	"0123456789"
# define HEX_BASE_L	"0123456789abcdef"
# define HEX_BASE_U	"0123456789ABCDEF"
# define CONVERSIONS	"cspdiuxX%nfge"
# define BREAKS	"cspdiuxX%"
# define FLAGS	"-0.*# +lh"

typedef struct	s_params
{
	va_list		ap;
	int		len_c;
	char		*flag;
	char		*str;
	char		*v_str;
	void		*v_p;
	int			asterisk;
	int			v_ast;
	char		v_c;
	intmax_t	v_int;
	char		conversion;
	size_t			width;
	int		precision;
	int			len;
	int			slen;
	int 		i;
}				t_ptf;

int		ft_printf(const char *str, ...);
void	ft_check_flag(t_ptf *parms);
int		ft_int_len(intmax_t d);
void	ft_print_x(t_ptf *parms);
char	*ft_itoa_base(uintmax_t nb, char* base);
void	ft_print_xup(t_ptf *parms);
void	ft_print_p(t_ptf *parms);
void	ft_print_u(t_ptf *parms);
void	ft_print_int(t_ptf *parms);
void	ft_print_char(t_ptf *parms);
void	ft_print_str(t_ptf *parms);
int		ft_match(char c, char *conversion);
void	ft_padding(char type, t_ptf *parms);
char	*ft_itoa_hex(uint32_t nb, char* base);
void 	ft_flag_width(t_ptf *parms);
void	ft_get_width(t_ptf *parms, int k);
void 	ft_flag_minus(t_ptf *parms);
void 	ft_flag_zeros(t_ptf *parms);
void	ft_flag_none(t_ptf *parms);
void 	ft_flag_asterisk(t_ptf *parms);
void	ft_set_conversion(t_ptf *parms);
void	ft_check_precision(t_ptf *parms);
void	ft_flag_precision(t_ptf *parms);
#endif
