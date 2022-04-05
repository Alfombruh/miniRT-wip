NAME 		= miniRT
CC			= clang
SFLAGS		= -fsanitize=address -g3
CFLAGS		= -Werror -Wextra -Wall -ggdb3
MLXFLAGS	= -L . -lmlx -framework OpenGL -framework Appkit
RM 			= rm -rf

FILES = srcs/main \
		srcs/utils/errors \
		srcs/utils/readrt \
		srcs/utils/elements \
		srcs/utils/values \
		srcs/utils/elements_linked

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all : $(NAME)

.c.o: $(FILES)
	@$(CC) $(SFLAGS) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) 
	@printf "\e[32mHold on! The code is compiling ⏳\e[0m\n"
	@$(MAKE) -s -C srcs/libft 
	@$(MAKE) -s -C mlx 
	@mv mlx/libmlx.a .
	@mv srcs/libft/libft.a .
	@$(CC) $(CFLAGS) $(SFLAGS) $(MLXFLAGS) $^ libft.a libmlx.a -o  $@
	@mv libmlx.a mlx/.
	@mv libft.a srcs/libft/.
	@printf "\e[32m\n🌈Ready to Trace some Rays🌈\e[0m\n"

clean :
	@$(MAKE) -s -C  mlx clean
	@$(MAKE) -s -C  srcs/libft clean
	@$(RM) $(OBJS)  *.dSYM
	@printf "\e[31m*.o=>🗑️\e[0m\n"

fclean : clean 
	@$(RM) $(NAME) srcs/libft/libft.a mlx/libmlx.a 
	@printf "\e[31m(miniRT && libmlx.a && libft.a)=>🗑️\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
