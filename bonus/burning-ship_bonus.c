/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning-ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:16:40 by habouda           #+#    #+#             */
/*   Updated: 2024/09/13 05:39:03 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_ship(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = fabs(x_temp);
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		put_pixel_to_image(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_pixel_to_image(fractal, fractal->x, fractal->y, fractal->color * i);
}

void	draw_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
}
