#ifndef FRACTOL_H
# define FRACTOL_H

#define SIZE 700

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
# include <math.h>
# include <pthread.h>
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
# define UP  			65362
# define LEFT  			65361
# define RIGHT 			65363
# define DOWN  			65364
# define ESC  			65307
# define R				27
# define Q				113
# define W				119

void	init_fractol(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	zoom(t_fractal *fractal, int x, int y, int zoom);
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
void	calculate_julia(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
void	draw_fractal(t_fractal *fractal, char *argv);
void	change_color(t_fractal *fractal);
void	calculate_mandle(t_fractal *fractal);
void	draw_mandle(t_fractal *fractal);
void	draw_ship(t_fractal *fractal);
void	calculate_ship(t_fractal *fractal);

int		exit_fractal(t_fractal *fractal);
int		mouse_hook(int code, int x, int y, t_fractal *fractal);
int		key_hook(int code, t_fractal *fractal);
int		parsing(int argc, char **argv);

#endif