NAME 		= miniRT
CC			= clang
SFLAGS		= -fsanitize=address -g3
CFLAGS		= -Werror -Wextra -Wall -ggdb3
MLXFLAGS	= -L . -lmlx -framework OpenGL -framework Appkit
RM 			= rm -rf

FILES = srcs/main	\
		srcs/utils/frees	\
		srcs/utils/readrt	\
		srcs/utils/values	\
		srcs/utils/errors	\
		srcs/utils/elements	\
		srcs/utils/elements_linked \
		srcs/utils/mlx_start \
		srcs/utils/ray_trace \
		srcs/utils/sphere_intersection

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all : $(NAME)

.c.o: $(SRCS)
	@$(CC) $(SFLAGS) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) 
	@printf "\e[32mHold on! The code is compiling ⏳\e[0m\n"
	@$(MAKE) -s -C srcs/libft 
	@$(MAKE) -s -C srcs/libvec
	@$(MAKE) -s -C srcs/libmlx 
	@mv srcs/libmlx/libmlx.a .
	@mv srcs/libft/libft.a .
	@mv srcs/libvec/libvec.a .
	@$(CC) $(CFLAGS) $(SFLAGS) $(MLXFLAGS) $^ libft.a libvec.a libmlx.a -o  $@
	@mv libmlx.a srcs/libmlx/.
	@mv libft.a srcs/libft/.
	@mv libvec.a srcs/libvec/.
	@printf "\e[32m\n🌈Ready to Trace some Rays🌈\e[0m\n"

clean :
	@$(MAKE) -s -C  srcs/libmlx clean
	@$(MAKE) -s -C  srcs/libft clean
	@$(MAKE) -s -C  srcs/libvec clean
	@$(RM) $(OBJS)  *.dSYM
	@printf "\e[31m*.o=>🗑️\e[0m\n"

fclean : clean 
	@$(RM) $(NAME) srcs/libft/libft.a srcs/libvec/libvec.a srcs/libmlx/libmlx.a 
	@printf "\e[31m(miniRT && libmlx.a && libft.a)=>🗑️\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
