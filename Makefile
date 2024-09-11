# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habouda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 01:37:02 by Habouda           #+#    #+#              #
#    Updated: 2024/09/05 22:08:04 by habouda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPIL #####################################################################

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

### MINILIBX #######################################################################

MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

### COMMANDS #######################################################################

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
