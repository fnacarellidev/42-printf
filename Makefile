NAME = libftprintf.a
SRC = $(addprefix ./src/, ft_printf.c utils.c)
OBJS = ft_printf.o utils.o

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRC)
	cc -c $(SRC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
