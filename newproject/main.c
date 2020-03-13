/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:46:25 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/13 17:11:42 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	messaggerror(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	basedefault(t_info *base)
{
	base->zoom = 20;
	base->color = 0x000000;
	base->movex = WX / 3;
	base->movey = WY / 3;
	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, WX, WY, "FDF");
	base->z_scale = 1;
	base->xn = 0;
	base->yn = 0;
	base->zn = 0;
	base->iso = 1;
	base->angle = 1;
	base->flag = 0;
}

int		main(int ac, char **av)
{
	t_info *base;

	if (ac != 2)
		messaggerror("usage: ./fdf map.fdf\n");
	if (!(base = (t_info *)malloc(sizeof(t_info))))
		return (0);
	reader(base, av[1]);
	basedefault(base);
	draw(base);
	mlx_key_hook(base->win_ptr, interaction, base);
	mlx_loop(base->mlx_ptr);
	return (0);
}
