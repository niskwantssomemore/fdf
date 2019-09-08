/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:30:25 by tstripeb          #+#    #+#             */
/*   Updated: 2019/09/08 19:27:44 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_base *base;
	int fd;
	
	fd = 0;
	if (ac == 2 && (base = (t_base *)malloc(sizeof(base))))
	{
		base->fd = 0;
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			base->fd = fd;
			printf("fd_1 = %i\n", base->fd);
			base->filename = av[1];
			if (!(ft_write_in_base(base)))
				return (0);

		}
		else 
		{
			ft_putendl("error");
			return (0);
		}
	}
	else
	{
			ft_putendl("error");
			return (0);
	}
}
