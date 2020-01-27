/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:50:31 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/27 15:44:35 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_freetime(char **result)
{
	int flag;

	flag = 0;
	while (result[flag])
	{
		free(result[flag]);
		flag++;
	}
	free(result);
}

int		main(int ac, char **av)
{
	t_info	*base;

	if (!(base = (t_info *)malloc(sizeof(t_info))))
		return (1);
	check(ac);
	parse(av[1], base);
	base->win = mlx_new_window(base->mlx, WX, WY, "Perfom");
	if (base->mlx == (void *)0)
		error(2);
	ft_draw(base);
	mlx_key_hook(base->win, button1, base);
	mlx_mouse_hook(base->win, mousemove, base);
	mlx_loop(base->mlx);
}
