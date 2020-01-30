/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathdraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:03:35 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/30 15:19:39 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mathx(t_info *base, int x, int y)
{
	double result;

	result = (M_SQRT2 / 2) * (y - x);
	result = base->scalex * result;
	return ((int)result);
}

int		mathy(t_info *base, int x, int y)
{
	double result;

	result = (sqrt(3 / 2) * base->map[x][y].z);
	result = result - (1 / sqrt(6) * (x + y));
	result = base->scaley * result;
	return ((int)result);
}

void	mathdraw(t_info *base)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < base->height)
	{
		while (y < base->width)
		{
			base->map[x][y].xn = mathx(base, x, y);
			base->map[x][y].yn = mathy(base, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}
