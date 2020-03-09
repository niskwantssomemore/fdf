/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:30:11 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/09 19:22:10 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mousemove(int click, int x, int y, t_info *base)
{
	if (click == 1 && x && y)
	{
		if (base->color == RED)
			base->color = BLUE;
		else if (base->color == BLUE)
			base->color = GREEN;
		else
			base->color = RED;
		ft_draw(base);
	}
	return (1);
}

void	changeview(t_info *base)
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
	if (keycode == 78)
	{
		base->scalex -= 1;
		base->scaley += 1;
	}
	if (keycode == 1)
	{
		base->view -= 1;
		changeview(base);
	}
	if (keycode == 15)
		base->color = RED;
	if (keycode == 11)
		base->color = BLUE;
	if (keycode == 5)
		base->color = GREEN;
	if (keycode == 35)
	{
		if (base->flag == 1)
			base->flag = 0;
		else
			base->flag = 1;
	}
	ft_draw(base);
	return (1);
}

int		button1(int keycode, t_info *base)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		base->posx += 30;
	if (keycode == 125)
		base->posy += 30;
	if (keycode == 123)
		base->posx -= 30;
	if (keycode == 126)
		base->posy -= 30;
	if (keycode == 13)
	{
		base->view += 1;
		changeview(base);
	}
	if (keycode == 69)
	{
		base->scalex += 1;
		base->scaley -= 1;
	}
	return (button2(keycode, base));
}
