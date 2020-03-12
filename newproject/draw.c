/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:19:26 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/12 17:48:26 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_info *base)
{
	*x = (*x - *y) * cos(base->angle);
	*y = (*y + *x) * sin(base->angle) - z;
	base->xn = (base->xn - base->yn) * cos(base->angle);
	base->yn = (base->yn + base->xn) * sin(base->angle) - base->zn;
}

void	setparams(t_info *base, float *x, float *y, int z)
{
	*x *= base->zoom;
	*y *= base->zoom;
	base->xn *= base->zoom;
	base->yn *= base->zoom;
	if (base->iso == 1)
		isometric(x, y, z, base);
	*x += base->movex;
	base->xn += base->movex;
	*y += base->movey;
	base->yn += base->movey;
}

void	basecolor(int z, t_info *base)
{
	if (!z && !base->zn)
		base->color = 0x00FF00;
	if ((!z && base->zn) || (z && !base->zn))
		base->color = 0x8B4513;
	if (z && base->zn && z == base->zn)
		base->color = 0xFFFFFF;
}

void	algorithm(t_info *base, float x, float y)
{
	float	xtemp;
	float	ytemp;
	int		temp;
	int		z;

	z = base->matrix[(int)y][(int)x];
	base->zn = base->matrix[(int)base->yn][(int)base->xn];
	z *= base->z_scale;
	base->zn *= base->z_scale;
	setparams(base, &x, &y, z);
	basecolor(z, base);
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
