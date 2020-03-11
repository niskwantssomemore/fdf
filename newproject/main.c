/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:46:25 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/11 22:35:03 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	interaction(int key, t_info *base)
{
	if (key == 53)
		exit(0);
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
	mlx_clear_window(base->mlx_ptr, base->win_ptr);
	draw(base);
	printf("%d\n", key);
	return (0);
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
}

int		main(int ac, char **av)
{
	t_info *base;

	if (ac != 2)
		messaggerror("usage: ./fdf map.fdf\n");
	if(!(base = (t_info *)malloc(sizeof(t_info))))
		return (0);
	printf("2\n");
	reader(base, av[1]);
	printf("3\n");
	basedefault(base);
	draw(base);
	mlx_key_hook(base->win_ptr, interaction, base);
	mlx_loop(base->mlx_ptr);
}
