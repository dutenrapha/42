# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 16:48:38 by rdutenke          #+#    #+#              #
#    Updated: 2020/05/06 23:31:24 by rdutenke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = libftprintf.h

FUNCTIONS = ft_printf.c

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
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all

$(DIRLIBFT)/libft.a:
	@$(MAKE) -C $(DIRLIBFT)