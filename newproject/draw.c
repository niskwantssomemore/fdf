/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:19:26 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/11 22:34:56 by tstripeb         ###   ########.fr       */
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

void	setparams(t_info *base, float *x, float *y)
{
	*x *= base->zoom;
	*y *= base->zoom;
	base->xn *= base->zoom;
	base->yn *= base->zoom;
	*x += base->movex;
	base->xn += base->movex;
	*y += base->movey;
	base->yn += base->movey;
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

void	algorithm(t_info *base, float x, float y)
{
	float	xtemp;
	float	ytemp;
	int		temp;
	int		z;
	int		zn;

	z = base->matrix[(int)y][(int)x];
	zn = base->matrix[(int)base->yn][(int)base->xn];
	z *= base->z_scale;
	zn *= base->z_scale;
	setparams(base, &x, &y);
	basecolor(z, zn, base);
	isometric(&x, &y, z);
	isometric(&base->xn, &base->yn, zn);
	xtemp = base->xn - x;
	ytemp = base->yn - y;
	temp = modulerb(xtemp, ytemp);
	xtemp /= temp;
	ytemp /= temp;
	while ((int)(x - base->xn) || (int)(y - base->yn))
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

	y = 0;
	printf("1\n");
	while (y < base->h)
	{
		x = 0;
		while (x < base->w)
		{
			if (x < base->w - 1)
			{
				base->xn = x + 1;
				base->yn = y;
				algorithm(base, x, y);
			}
			if (y < base->h - 1)
			{
				base->yn = y + 1;
				base->xn = x;
				algorithm(base, x, y);
			}
			x++;
		}
		y++;
	}
}
