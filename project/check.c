/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:50:19 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/09 20:15:15 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Invalid number of arguments.\n", 2);
		ft_putstr_fd("Usage: ./fdf file.fdf\n", 2);
		exit(0);
	}
}

void	error(int er)
{
	if (er == 1)
		ft_putstr_fd("ERROR: Invalid map\n", 2);
	if (er == 2)
		ft_putstr_fd("ERROR: MLX failed\n", 2);
	exit(0);
}
