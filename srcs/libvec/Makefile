NAME = libvec.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf
FILES = vec_utils \
		vec_basics \
		vec_products \
		vec_rotations

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

.c.o: $(SRCS)
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
