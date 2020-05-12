# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 16:48:38 by rdutenke          #+#    #+#              #
#    Updated: 2020/05/11 18:27:14 by rdutenke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = libftprintf.h

FUNCTIONS = ft_printf.c ft_check_flag.c ft_int_len.c ft_print_x.c ft_itoa_base.c

FLAGS = -Wall -Werror -Wextra 

DIRLIBFT = ../libft

FUNCTIONS_O = $(subst .c,.o,$(FUNCTIONS))

OBJ = $(subst .c,.o,$(FUNCTIONS))

all:	$(NAME)

$(NAME):	$(DIRLIBFT)/libft.a
		@clang $(FLAGS) -c $(FUNCTIONS)
		@ar rc $(NAME) $(FUNCTIONS_O) $(DIRLIBFT)/*.o
		@ranlib $(NAME)

clean:
	@/bin/rm -f *.o $(DIRLIBFT)/*.o

fclean: clean
	@/bin/rm -f $(NAME) $(DIRLIBFT)/libft.a

re:	fclean all

run:	re
	@clear
	@clang $(FLAGS) -g main.c -L. -lftprintf
	@./a.out

$(DIRLIBFT)/libft.a:
	@$(MAKE) -C $(DIRLIBFT)
