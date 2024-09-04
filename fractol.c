/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by habouda           #+#    #+#             */
/*   Updated: 2024/09/04 17:24:51 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



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
	while ()
	mlx_pixel_put(fractal->mlx, fractal->window, 100, 100, 0xFFFFFF);
	mlx_loop(fractal->mlx);
	
}
