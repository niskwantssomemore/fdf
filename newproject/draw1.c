/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:48:51 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/11 22:02:22 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*y + *x) * sin(1) - z;
}

float	modulerb(float xtemp, float ytemp)
{
	if (xtemp < 0)
		xtemp = -xtemp;
	if (ytemp < 0)
		ytemp = -ytemp;
	if (xtemp > ytemp)
		return (xtemp);
	else
		return (ytemp);
}

void	setparams(t_info *base, float *x, float *y, float *xn, float *yn)
{
	*x *= base->zoom;
	*y *= base->zoom;
	*xn *= base->zoom;
	*yn *= base->zoom;
	*x += base->movex;
	*xn += base->movex;
	*y += base->movey;
	*yn += base->movey;
}

void	basecolor(int z, int zn, t_info *base)
{
	if (!z && !zn)
		base->color = 0x00FF00;
	if ((!z && zn) || (z && !zn))
		base->color = 0x8B4513;
	if (z && zn && z == zn)
		base->color = 0xFFFFFF;
}

void	algorithm(t_info *base, float x, float y, float xn, float yn)
{
	float	xtemp;
	float	ytemp;
	int		temp;
	int		z;
	int		zn;

	z = base->matrix[(int)y][(int)x];
	zn = base->matrix[(int)yn][(int)xn];
	z *= base->z_scale;
	zn *= base->z_scale;
	setparams(base, &x, &y, &xn, &yn);
	basecolor(z, zn, base);
	isometric(&x, &y, z);
	isometric(&xn, &yn, zn);
	xtemp = xn - x;
	ytemp = yn - y;
	temp = modulerb(xtemp, ytemp);
	xtemp /= temp;
	ytemp /= temp;
	while ((int)(x - xn) || (int)(y - yn))
	{
		mlx_pixel_put(base->mlx_ptr, base->win_ptr, x, y, base->color);
		x = xtemp + x;
		y = ytemp + y;
	}
}

void	draw(t_info *base)
{
	int	x;
	int y;

	y  = 0;
	while (y < base->h)
	{
		x = 0;
		while (x < base->w)
		{
			if (x < base->w - 1)
				algorithm(base, x, y, x + 1, y);
			if (y < base->h - 1)
				algorithm(base, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
