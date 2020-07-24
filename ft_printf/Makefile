# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 16:48:38 by rdutenke          #+#    #+#              #
#    Updated: 2020/07/23 18:35:32 by rdutenke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = libftprintf.h

COMPI = clang

MAIN = main.c

FUNCTIONS = ft_printf.c ft_check_flag.c ft_int_len.c ft_print_x.c ft_itoa_base.c ft_print_xup.c \
			ft_print_p.c ft_print_u.c ft_print_int.c ft_print_char.c ft_print_str.c\
			ft_match.c ft_padding.c ft_itoa_hex.c ft_flag_width.c ft_get_width.c ft_flag_minus.c\
			ft_flag_zeros.c ft_flag_none.c ft_flag_asterisk.c ft_set_conversion.c ft_check_precision.c\
			ft_flag_precision.c ft_putchar_fd.c ft_strlen.c ft_calloc.c ft_substr.c ft_atoi.c ft_strchr.c \
			ft_putstr_fd.c ft_strdup.c ft_memset.c ft_strjoin.c ft_itoa.c ft_strrchr.c\

FLAGS = -Wall -Wextra -Werror

FUNCTIONS_O = $(subst .c,.o,$(FUNCTIONS))

OBJ = $(subst .c,.o,$(FUNCTIONS))

all:	$(NAME)

$(NAME):	
		@$(COMPI) $(FLAGS) -c $(FUNCTIONS)
		@ar rc $(NAME) $(FUNCTIONS_O) 


clean:
	@/bin/rm -f *.o 

fclean: clean
	@/bin/rm -f $(NAME) 

re:	fclean all

run:	re
	@clear
	@$(COMPI) $(FLAGS) main.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main2.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main3.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main4.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main5.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main6.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main7.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main8.c -L. -lftprintf
	@./a.out 
	@$(COMPI) $(FLAGS) main10.c -L. -lftprintf
	@./a.out 

test:	fclean 
	@$(COMPI) $(FLAGS) -g $(MAIN) $(FUNCTIONS) 
