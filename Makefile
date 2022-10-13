NAME = libftprintf.a
SRC = $(addprefix ./src/, ft_printf.c utils.c)
BONUS_SRC = $(addprefix ./bonus_src/, ft_printf_bonus.c utils_bonus.c)
OBJS = ft_printf.o utils.o
BONUS_OBJS = ft_printf_bonus.o utils_bonus.o
CFLAGS = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRC)
<<<<<<< HEAD
	$(CFLAGS) -c $(SRC)

bonus : $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

$(BONUS_OBJS) : $(BONUS_SRC)
	$(CFLAGS) -I includes/ -c $(BONUS_SRC)
=======
	cc -c $(SRC)
>>>>>>> 3211eb68842b87f274c11c8c00600a9f52c621a2

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
