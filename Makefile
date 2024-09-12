CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -Iminilibx-linux
LDFLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm
NAME 	= fractol
NAMEB	= fractol_bonus
### SRC ########################################################################

SRCS	=	fractol.c \
			init.c \
			mouse_keyboard.c \
			utils.c \
			julia.c \
			mandle.c \
			parsing.c \

SRCS_B  = 	bonus/fractol_bonus.c \
			bonus/init_bonus.c \
			bonus/mouse_keyboard_bonus.c \
			bonus/utils_bonus.c \
			bonus/julia_bonus.c \
			bonus/mandle_bonus.c \
			bonus/burning-ship_bonus.c \

### OBJS ###########################################################################

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

### LIBFT ###########################################################################

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

### MLX ###########################################################################

MLX_DIR = ./minilibx-linux
MLX_GIT = https://github.com/42Paris/minilibx-linux.git
MLX = $(MLX_DIR)/libmlx.a

### RULES ######################################a#####################################

all : $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)


bonus : $(MLX) $(NAMEB)

$(NAMEB): $(OBJS_B) $(LIBFT) $(MLX)
	@$(CC) $(OBJS_B) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAMEB)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then git clone $(MLX_GIT) $(MLX_DIR); fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	rm -f $(NAMEB)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all re fclean clean
