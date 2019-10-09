/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:06:55 by sazalee           #+#    #+#             */
/*   Updated: 2019/10/09 18:48:26 by sazalee          ###   ########.fr       */
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
	char	*buf;
	int		count;

	count = 0;
	while (get_next_line(fd, &buf) == 1)
		count++;
	fdf->number_lines = count;
	fdf->x = 0;
	fdf->y = 0;
	fdf->startofx = 0;
	fdf->startofy = 0;
	fdf->scaleofx = 0;
	fdf->scaleofy = 0;
	close(fd);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (NULL);
	check_ac(ac);
	manylines_coords(&fdf, fd);
	fd = open(av[1], O_RDONLY);
}
