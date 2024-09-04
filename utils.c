/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:06:01 by habouda           #+#    #+#             */
/*   Updated: 2024/09/05 00:16:21 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}
void	change_color(t_fractal *fractal)
{
	if (fractal->color == 0xFCBE11)
	{
		fractal->color = 0x8B0000;
	}
	else if (fractal->color == 0x8B0000)
	{
		fractal->color = 0x0bf0fb;
	}
	else if (fractal->color == 0x0bf0fb)
	{
		fractal->color =0xFCBE11;
	}
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}