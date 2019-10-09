/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:06:55 by sazalee           #+#    #+#             */
/*   Updated: 2019/10/09 17:09:02 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_ac(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Invalid number of arguments.\n", 2);
		ft_putstr_fd("Usage: ./fdf file.fdf\n", 2);
		exit(0);
	}
}

void	manylines_coords(t_fdf *fdf, int fd)
{


int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	check_ac(ac);
}
