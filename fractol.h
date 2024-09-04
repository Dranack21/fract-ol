#ifndef FRACTOL_H
# define FRACTOL_H

#define SIZE 700;

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}		t_fractal;

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46



void	init_fractol(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	zoom(t_fractal *fractal, int x, int y, int zoom);

int	mouse_hook(int code, t_fractal *fractal);
int	key_hook(int code, t_fractal *fractal);

#endif