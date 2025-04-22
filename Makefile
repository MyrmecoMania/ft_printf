NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror -g3

SRC = ft_putnbr.c ft_printf.c 

OBJ = $(SRC:.c=.o)

.c.o:
		cc $(FLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
		ar -rc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re