/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by habouda           #+#    #+#             */
/*   Updated: 2024/09/04 23:35:48 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal *fractal, char *argv)
{		
	if (ft_strncmp(argv, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = 0.1;
			fractal->cy = 0.785;
		}
	}
	draw_julia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
	0);
}


int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	if (argc != 2)
		return (ft_putendl_fd("not enough arguments available args are julia, Mandle", 2), 0);
	fractal = malloc(sizeof(t_fractal));
	init_fractol(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	
}
