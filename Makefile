NAME = cub3d

CC = cc -g3
INC = ./include
LIBFT = ./include/libft/libft.a
LIBMLX = ./include/mlx/libmlx.a
CFLAGS = -Wall -Werror -Wextra -I$(INC)
MLXFLAGS = -framework OpenGL -framework AppKit
INCLUDE = -I 
EXIT_DIR = ./src/exit

SRCS = ./src/main.c \
		./src/parsing/validate_cmdline.c ./src/parsing/maptolayout.c ./src/parsing/fill_layout.c ./src/parsing/parsing_utils.c\
		./src/parsing/maptostruct.c ./src/parsing/xpm_parsing.c ./src/parsing/color_parsing.c ./src/parsing/color_parsing2.c\
		./src/parsing/parse_point.c ./src/parsing/initial_check.c ./src/execution/add_textures.c ./src/execution/windonhooks2.c\
		./src/execution/execution.c ./src/execution/drawminimap.c ./src/execution/mark_player.c ./src/execution/windonhooks.c\
		./src/exit/error.c ./src/exit/free.c ./src/execution/textmappin.c ./src/execution/execution2.c ./src/execution/execution3.c\
		./src/execution/exutils.c ./src/parsing/utils1.c ./src/exit/freeutils.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./include/mlx
	@$(MAKE) -C ./include/libft
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBMLX) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) clean -C ./include/libft
	@$(MAKE) clean -C ./include/mlx

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C ./include/libft
	@$(MAKE) clean -C ./include/mlx

re: fclean all

.PHONY: all clean fclean re