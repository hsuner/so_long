NAME			=	so_long

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC				=	main.c \
					check.c \
					utils.c \
					game.c \
					path_finder.c \
					xpm_operations.c

LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	minilibx

all:	$(NAME)

$(NAME):	$(LIBFT) mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx
	@printf "\n\033[96m   Built 🛠 \033[0m\n\n"

$(LIBFT):
	@make -C $(LIBFT_PATH) all

mlx:
	@make -C $(MINILIBX_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MINILIBX_PATH) clean
	@printf "\n\033[95m   Deleted ⛔️ \033[0m\n\n"

fclean:
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(NAME)
	@printf "\n\033[95m   Deleted ⛔️ \033[0m\n\n"

re:					fclean all

.PHONY:				all clean fclean re libft
