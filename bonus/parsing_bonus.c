/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:05:32 by habouda           #+#    #+#             */
/*   Updated: 2024/09/12 23:07:26 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parsing(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandle", 7) == 0 || ft_strncmp(argv[1], "ship", 5) == 0)
	{
		if (argc != 2)
			return (write(2, "Too manys arguments", 20), 0);
		else
			return (1);
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
			return (write(2, "wrong args for julia", 21), 0);
		if (argv[2] && argv[3])
		{
			if (ft_is_digit_or_float(argv[2]) && ft_is_digit_or_float(argv[3]))
				return (1);
			return (0);
		}
	}
	write(2, "use julia orn mandle", 21);
	return (0);	
}
