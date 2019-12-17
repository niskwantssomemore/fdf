/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:50:31 by sazalee           #+#    #+#             */
/*   Updated: 2019/12/17 15:50:32 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_info	*base;

	count = 0;
	if (!(base = (t_info *)malloc(sizeof(t_info))))
		return (1);
	check(ac);
	parse(av[1], base);
	base->mlx = mlx_new_window(base->mlx, 1000, 1000, "perfom");
	if (base->mlx == (void *)0)
		error(2);
}
