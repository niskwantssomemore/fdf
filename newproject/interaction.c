/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:57:19 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/13 17:59:04 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	randomcolor(t_info *base)
{
	size_t randcolor;

	randcolor = rand();
	base->color = rand() % randcolor;
}

int		is_key(int key)
{
	if (key == 126 || key == 125 || key == 123
		|| key == 124 || key == 69 || key == 24 || key == 78
		|| key == 27 || key == 13 || key == 1 || key == 49
		|| key == 15 || key == 37 || key == 12 || key == 0)
		return (1);
	return (0);
}

void	do_key(int key, t_info *base)
{
	if (key == 0)
		base->flag = 0;
	if (key == 126)
		base->movey -= 10;
	if (key == 125)
		base->movey += 10;
	if (key == 123)
		base->movex -= 10;
	if (key == 124)
		base->movex += 10;
	if (key == 69 || key == 24)
		base->zoom += 1;
	if (key == 78 || key == 27)
		base->zoom > 0 ? base->zoom-- : base->zoom;
	if (key == 13)
		base->z_scale += 1;
	if (key == 1)
		base->z_scale -= 1;
	if (key == 49)
		base->iso = (base->iso == 1 ? 0 : 1);
	if (key == 15)
		base->angle += 0.05;
	if (key == 37)
		base->angle -= 0.05;
}

int		interaction(int key, t_info *base)
{
	if (is_key(key))
	{
		mlx_clear_window(base->mlx_ptr, base->win_ptr);
		if (key == 12)
		{
			base->flag = 1;
			randomcolor(base);
		}
		do_key(key, base);
		draw(base);
	}
	if (key == 53)
	{
		mlx_destroy_window(base->mlx_ptr, base->win_ptr);
		free(base->matrix);
		exit(0);
	}
	return (0);
}
