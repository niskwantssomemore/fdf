/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:50:31 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/20 18:53:32 by sazalee          ###   ########.fr       */
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
	base->mlx = mlx_new_window(base->mlx, WX, WY, "Perfom");
	if (base->mlx == (void *)0)
		error(2);
}
