/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:30:11 by sazalee           #+#    #+#             */
/*   Updated: 2020/02/06 05:13:22 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menuer(t_info *base)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = base->mlx;
	win = base->win;
	mlx_string_put(mlx, win, 65, y += 20, 0xEAEAEA, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, 0xEAEAEA, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, 0xEAEAEA, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, 0xEAEAEA, "Rotate: Press & Move");
}

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

void	changeview(t_info *base, int flag)
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
		changeview(base, -1);
	}
	if (keycode == 15)
		base->color = RED;
	if (keycode == 11)
		base->color = BLUE;
	if (keycode == 5)
		base->color = GREEN;
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
		changeview(base, 1);
	}
	if (keycode == 69)
	{
		base->scalex += 1;
		base->scaley -= 1;
	}
	return (button2(keycode, base));
}
