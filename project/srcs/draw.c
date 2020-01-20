/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:45:17 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/20 18:47:40 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw(t_info *base, int x, int y)
{
	int coordn[2];
	int coordk[2];

	coordn[0] = base->map[x][y].xn;
	coordn[1] = base->map[x][y].yn;
	if (y < width - 1)
	{
		coordk[0] = map[x][y + 1].xn;
		coordk[1] = map[x][y + 1].yn;
		draw_1(base, coordn, coordk);
	}
	if (x < height - 1)
	{
		coordk[0] = map[x + 1][y].xn;
		coordk[1] = map[x + 1][y].yn;
		draw_1(base, coordn, coordk);
	}
}

void	draw_1(t_info *base, int *coordn, int *coordk)
{
	int delta[2];
	int sign[2];
	int error[2];

	delta[0] = ft_modul(coordk[0] - coordn[0]);
	delta[1] = ft_modul(coordk[1] - coordn[1]);
	sign[0] = (coordk[0] - coordn[0] > 0 ? 1 : -1);
	sign[1] = (coordk[1] - coordn[1] > 0 ? 1 : -1);
	error[0] = delta[0] - delta[1];
	while (coordn[0] != coordk[0] || coordn[1] != coordk[1])
	{
		mlx_pixel_put(base->mlx, base->win, base->scalex
				+ coordn[0], base->scaley + coordn[1], color);
		error[1] = error[0] * 2;
		if (error[1] > -delta[1])
		{
			error[0] -= delta[1];
			coordn[0] += sign[0];
		}
		if (error[1] < delta[0])
		{
			error[0] += delta[0];
			coordn[1] += sign[1];
		}
	}
}
