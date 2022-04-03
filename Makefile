NAME = miniRT
CC = clang
CFLAGS = -Werror -Wall -Wextra
SFLAGS = -fsanitize=address -g3
RM = rm -rf

FILES = main 

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -c /mlx
	mv /mlx/mlx.a .
	$(CC) $(CFLAGS) mlx.a $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all .c.o clean fclean re

