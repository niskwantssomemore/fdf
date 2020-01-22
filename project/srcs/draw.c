/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:45:17 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/22 19:07:59 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixelmls(t_info *base, int x, int y, int color)
{
	mlx_pixel_put(base->mlx, base->win, base->posx + x, base->posy + y, color);
}

void	ft_draw2(t_info *base, int *coord1, int *coord2)
{
	int delta[2];
	int sign[2];
	int error[2];

	delta[0] = ft_modul(coord2[0] - coord1[0]);
	delta[1] = ft_modul(coord2[1] - coord1[1]);
	sign[0] = (coord2[0] - coord1[0] > 0 ? 1 : -1);
	sign[1] = (coord2[1] - coord1[1] > 0 ? 1 : -1);
	error[0] = (delta[0] - delta[1] > 0 ? delta[0] : -delta[1]) / 2;
	while (coord1[0] != coord2[0] || coord1[1] != coord2[1])
	{
		pixelmls(base, coord1[0], coord1[1], base->color);
		error[1] = error[0];
		if (error[1] > -delta[0])
		{
			error[0] -= delta[1];
			coord1[0] += sign[0];
		}
		if (error[1] < delta[1])
		{
			error[0] += delta[0];
			coord1[1] += sign[1];
		}
	}
}

void	ft_draw1(t_info *base, int x, int y)
{
	int coord1[2];
	int coord2[2];

	coord1[0] = base->map[x][y].xn;
	coord1[1] = base->map[x][y].yn;
	if (y < base->width - 1)
	{
		coord2[0] = base->map[x][y + 1].xn;
		coord2[1] = base->map[x][y + 1].yn;
		ft_draw2(base, coord1, coord2);
	}
	if (x < base->height - 1)
	{
		coord2[0] = base->map[x + 1][y].xn;
		coord2[1] = base->map[x + 1][y].yn;
		ft_draw2(base, coord1, coord2);
	}
}

void	ft_draw(t_info *base)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mathdraw(base);
	mlx_clear_window(base->mlx, base->win);
	while (x < base->height)
	{
		while (y < base->width)
		{
			ft_draw1(base, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}
