NAME = libftprintf.a

FUNCTIONS = ft_printf.c 

FUNCTIONS_O  = $(subst .c,.o,$(FUNCTIONS))

all: $(NAME)
$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FUNCTIONS)
	@ar rc $(NAME) $(FUNCTIONS_O) 
	@ranlib $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)
	
re: fclean all run

run:
	@gcc -Wall -Wextra -Werror main.c -L. -lftprintf
	@./a.out
