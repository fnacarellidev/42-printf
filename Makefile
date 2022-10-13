NAME = libftprintf.a
SRC = $(addprefix ./src/, ft_printf.c utils.c)
OBJS = ft_printf.o utils.o
CFLAGS = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRC)
	$(CFLAGS) -I includes/ -c $(SRC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
