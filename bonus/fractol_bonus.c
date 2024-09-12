/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by habouda           #+#    #+#             */
/*   Updated: 2024/09/12 17:33:50 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal *fractal, char *argv)
{		
	if (ft_strncmp(argv, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = ft_atof(argv[2]) ;
			fractal->cy = ft_atof(argv[3]);
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

	argc = argc + 0;
	fractal = malloc(sizeof(t_fractal));
	init_fractol(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	
}
