/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:46:09 by habouda           #+#    #+#             */
/*   Updated: 2024/09/05 18:49:49 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandle(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "mandle";
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->cy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x00000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}

void	draw_mandle(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_mandle(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}
