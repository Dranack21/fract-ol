CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -Iminilibx-linux
LDFLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm
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
MLX = $(MLX_DIR)/libmlx.a

### RULES ###########################################################################

all : $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then git clone $(MLX_GIT) $(MLX_DIR); fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean : clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all re fclean clean
