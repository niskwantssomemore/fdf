/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:30:11 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/25 15:14:48 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mousemove(int click, int x, int y, t_info *base)
{
	if (click == 1 && x && y)
	{
		if (base->color == RED)
			base->color = BLUE;
		else if (click == BLUE)
			base->color = GREEN;
		else
			base->color = RED;
		ft_draw(base);
	}
	return (1);
}

void	changeview(t_info base, int flag)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < base->height)
	{
		while (y < base->width)
		{
			if (base->map[x][y].zn != 0)
			{
				base->map[x][y].z = base->map[x][y].zn * base->view;
				base->map[x][y].xn = mathx(base, x, y);
				base->map[x][y].yn = mathy(base, x, y);
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int		button2(int keycode, t_info *base)
{
	if (keycode == -)
	{
		base->scalex -= 1;
		base->scaley += 1;
	}
	if (keycode == s)
	{
		base->view -= 1;
		changeview(base, -1);
	}
	if (keycode == r)
		base->color = RED;
	if (keycode == b)
		base->color = BLUE;
	if (keycode == g)
		base->color = GREEN;
	ft_draw(base);
	return (1);
}

int		button1(int keycode, t_info *base)
{
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == arrow)
		base->posx += 30;
	if (keycode == arrow)
		base->posy += 30;
	if (keycode == arrow)
		base->posx -= 30;
	if (keycode == arrow)
		base->posy -= 30;
	if (keycode == w)
	{
		base->view += 1;
		changeview(base, 1);
	}
	if (keycode == +)
	{
		base->scalex += 1;
		base->scaley -= 1;
	}
	return (button2(keycode, base));
}
