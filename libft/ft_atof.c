/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:15:34 by habouda           #+#    #+#             */
/*   Updated: 2024/09/13 04:46:40 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof_part(const char *str, int *i)
{
	double	result;
	double	div;

	result = 0.0;
	div = 1.0;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] && ft_isdigit(str[*i]))
		{
			result = result * 10.0 + (str[*i] - '0');
			div *= 10.0;
			(*i)++;
		}
	}
	return (result / div);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_atof_part(str, &i);
	return (result * sign);
}
