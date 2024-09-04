/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by habouda           #+#    #+#             */
/*   Updated: 2024/09/04 17:37:11 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

// void	draw_fractal(t_fractal fractal, char *argv)
// {		
// 	if (ft_strncmp(argv, "julia", 6) == 0)
// 		draw_julia(fractal);
// 	if (ft_strncmp(argv, "mandel", 7) == 0)
// 		draw_mandel(fractal);
// }


int	main()
{
	t_fractal	*fractal;

	// if (argc != 2)
	// 	return (ft_putendl_fd("not enough arguments available args are julia, Mandle", 2), 0);
	fractal = malloc(sizeof(t_fractal));
	init_fractol(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_pixel_put(fractal->mlx, fractal->window, 100, 100, 0xFFFFFF);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	mlx_loop(fractal->mlx);
	
}
