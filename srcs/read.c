/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:49:10 by sazalee           #+#    #+#             */
/*   Updated: 2019/10/09 19:48:38 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*spacer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			str[i] = ' ';
	}
	return (str);
}

int		countersplits(char **splitchar)
{
	int i;

	i = 0;
	while (splitchar[i])
		i++;
	return (i);
}

int		ft_getnumber(char *str)
{
	int	i;
	int	result;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	return (sign * result);
}

void	reader(t_fdf *fdf, int fd)
{
	if (!(fdf->coords = (int **)malloc(sizeof(int *) * fdf->number_lines)))
		exit(1);
	while (get_next_line(fd, &(fdf->oneline)) == 1)
	{
		fdf->count = 0;
		fdf->oneline = spacer(fdf->oneline);
		fdf->splitchar = ft_strsplit(fdf->oneline, ' ');
		fdf->number_columns = countersplits(splitchar);
		if (!(fdf->coords[fdf->x] = (int *)malloc(sizeof(int)
						* fdf->number_columns)))
			exit(1);
		while (fdf->splitchar[fdf->y])
		{
			fdf->coords[fdf->x][fdf->y] = ft_getnumber(fdf->splitchar[fdf->y]);
			fdf->y++;
		}
		fdf->coords[fdf->x][fdf->y] = '\0';
		fdf->x++;
		fdf->y = 0;
		free(splitchar);
	}
}
