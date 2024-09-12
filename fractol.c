/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by habouda           #+#    #+#             */
/*   Updated: 2024/09/12 23:01:23 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal *fractal, char *argv)
{		
	if (ft_strncmp(argv, "julia", 6) == 0)
	{
		draw_julia(fractal);
	}
	else if (ft_strncmp(argv, "mandle", 7) == 0)
		draw_mandle(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
	0);
}


int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	if (parsing(argc, argv) == 0)
		return (0);
	fractal = malloc(sizeof(t_fractal));
	init_fractol(fractal);
	argc = argc + 0;
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->name = "julia";
		fractal->cx = atof(argv[2]);
		fractal->cy = atof(argv[3]);
	}
	if (ft_strncmp(argv[1], "mandle", 7) == 0)
	{
		fractal->name = "mandle";
	}
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, fractal->name);
	mlx_loop(fractal->mlx);
}
