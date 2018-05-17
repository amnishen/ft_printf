NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
FILES = *.c \
		./libs_src/*.c
OBJ = *.o 
HEAD = -c -I ft_printf.h 

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(HEAD) $(FILES) 
	ar rc $(NAME) $(OBJ) 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
