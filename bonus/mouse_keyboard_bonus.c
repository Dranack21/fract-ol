/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keyboard_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:51:02 by habouda           #+#    #+#             */
/*   Updated: 2024/09/13 04:10:35 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int code, t_fractal *fractal)
{
	if (code == ESC)
		exit_fractal(fractal);
	else if (code == UP)
		fractal->offset_y = fractal->offset_y - 42 / fractal->zoom;
	else if (code == DOWN)
		fractal->offset_y = fractal->offset_y + 42 / fractal->zoom;
	else if (code == RIGHT)
		fractal->offset_x = fractal->offset_x + 42 / fractal->zoom;
	else if (code == LEFT)
		fractal->offset_x = fractal->offset_x - 42 / fractal->zoom;
	else if (code == W)
		change_color(fractal);
	else if (code == Q)
		init_fractol(fractal);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_fractal *fractal)
{
	if (code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	if (code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	draw_fractal(fractal, fractal->name);
	return (0);
}

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}
