# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 16:48:38 by rdutenke          #+#    #+#              #
#    Updated: 2020/06/04 16:42:09 by rdutenke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = libftprintf.h

COMPI = clang

MAIN = main6.c

FUNCTIONS = ft_printf.c ft_check_flag.c ft_int_len.c ft_print_x.c ft_itoa_base.c ft_print_xup.c \
			ft_print_p.c ft_print_u.c ft_print_int.c ft_print_char.c ft_print_str.c\
			ft_match.c ft_padding.c ft_itoa_hex.c ft_flag_width.c ft_get_width.c ft_flag_minus.c\
			ft_flag_zeros.c ft_flag_none.c ft_flag_asterisk.c ft_set_conversion.c ft_check_precision.c\
			ft_flag_precision.c \

FLAGS = -Wall -Werror -Wextra 

DIRLIBFT = ../libft

FUNCTIONS_O = $(subst .c,.o,$(FUNCTIONS))

OBJ = $(subst .c,.o,$(FUNCTIONS))

all:	$(NAME)

$(NAME):	$(DIRLIBFT)/libft.a
		@$(COMPI) $(FLAGS) -c $(FUNCTIONS)
		@ar rc $(NAME) $(FUNCTIONS_O) $(DIRLIBFT)/*.o
		@ranlib $(NAME)

clean:
	@/bin/rm -f *.o $(DIRLIBFT)/*.o

fclean: clean
	@/bin/rm -f $(NAME) $(DIRLIBFT)/libft.a

re:	fclean all

run:	re
	@clear
	@$(COMPI) $(FLAGS) $(MAIN) -L. -lftprintf
	@./a.out

test:	fclean $(DIRLIBFT)/libft.a
	@$(COMPI) $(FLAGS) -g $(MAIN) $(FUNCTIONS) -L. $(DIRLIBFT)/libft.a


$(DIRLIBFT)/libft.a:
	@$(MAKE) -C $(DIRLIBFT)
