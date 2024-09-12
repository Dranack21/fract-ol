CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm
NAME 	= fractol

### SRC ########################################################################

SRCS	=	fractol.c \
			init.c \
			mouse_keyboard.c \
			utils.c \
			julia.c \
			mandle.c \
			burning-ship.c \

### OBJS ###########################################################################

OBJS	= $(SRCS:.c=.o)

### LIBFT ###########################################################################

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

### MLX ###########################################################################

MLX_DIR = ./minilibx-linux
MLX_GIT = https://github.com/42Paris/minilibx-linux.git

### RULES ###########################################################################

all: $(LIBFT) $(MLX_DIR)/libmlx.a $(NAME)

$(MLX_DIR)/libmlx.a:
	git clone $(MLX_GIT) $(MLX_DIR) || true
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
