# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Lia <Lia@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/26 16:51:12 by Lia               #+#    #+#              #
#    Updated: 2020/03/30 15:54:09 by Lia              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c

OBJ = ft_printf.o

LIBDIR = ./Libft

OBJLIB = $(LIBDIR)/*.o

HEADER = ft_printf.h

FLAG = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBDIR)/libft.a
	ar rc $(NAME) $(OBJ) $(OBJLIB)
	ranlib $(NAME)

.o: .c 
	gcc -c $(FLAG) $(FILES) -I $(HEADER)

$(LIBDIR)/libft.a:
	$(MAKE) -C $(LIBDIR)

test: $(NAME)
	gcc $(FLAG) main.c $(NAME)
	./a.out
	
clean:
	rm -f $(OBJECTS1) $(OBJECTS2)

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re: fclean all
