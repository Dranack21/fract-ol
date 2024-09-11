/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by habouda           #+#    #+#             */
/*   Updated: 2024/09/05 19:27:09 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal *fractal, char *argv)
{		
	if (ft_strncmp(argv, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.744 ;
			fractal->cy = 0.148;
		}
		draw_julia(fractal);
	}
	else if (ft_strncmp(argv, "mandle", 7) == 0)
		draw_mandle(fractal);
	else if (ft_strncmp(argv, "ship", 5) == 0)
		draw_ship(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
	0);
}


int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	if (argc != 2)
		return (ft_putendl_fd("Use ./test_mlx with julia or mandle ", 2), 0);
	// if (ft_strncmp(argv[1], "mandle", 7) != 0 && ft_strncmp(argv[1], "julia", 6) != 0 && ft_strncmp(argv[1], "ship", 5) == 0)
	// 	return(ft_putendl_fd("Wrong arguments use mandle or julia", 2), 0);
	fractal = malloc(sizeof(t_fractal));
	init_fractol(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	
}
