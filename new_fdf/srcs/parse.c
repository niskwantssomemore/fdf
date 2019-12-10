/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:00:12 by tstripeb          #+#    #+#             */
/*   Updated: 2019/12/05 17:36:26 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		countw(char *format)
{
	int index;
	int counter;

	index = 0;
	counter = 0;
	while (format[index] != '\0')
	{
		if (format[index] == ' ')
			counter++;
		index++;
	}
	if (counter > 0)
		counter++;
	return (counter);
}

int		params(char *filebase, int count)
{
	char		*line;
	int		fd;
	int		res1;
	int		res2;
	int		temp;

	res1 = 0;
	if ((fd = open(filebase, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		temp = countw(line);
		if (res1 == 0)
			res2 = temp;
		else if (res2 == temp)
			res2 = temp;
		else if (res2 != temp)
			error(1);
		res1++;
	}
	close(fd);
	return (count == 1 ? res1 : res2);
}

int	countlength(char *field, int z)
{
	int count;

	count = 0;
	while(field[z] != ' ' || field[z] != '\0')
	{
		count++;
		z++;
	}
	return (count);
}

char	**transport(char *field, int clines)
{
	char	**result;
	int	x;
	int	y;
	int	z;
	int	ccolumn;

	x = 0;
	y = 0;
	z = 0;
	if (!(result = (char**)malloc(sizeof(char *) * clines + 1)))
		return (NULL);
	while (field[z] != '\0')
	{
		ccolumn = countlength(field, z);
		if (!(result[x] = (char*)malloc(sizeof(char) * ccolumn + 1)))
			return (NULL);
		while (y <= ccolumn)
			result[x][y++] = field[z++];
		y = 0;
		result[x][ccolumn] = '\0';
		x++;
	}
	result[x] = NULL;
	return (result);
}

void	read(char *filebase, t_info *base)
{
	int	fd;
	int	x;
	int	y;
	char	*line;
	char	**result;

	x = 0;
	y = 0;
	if ((fd = open(filebase, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		result = transport(line, countw(line));

void	parse(char *filebase, t_info *base)
{
	int count;

	count = 0;
	if ((base->mlx = mlx_init()) == (void *)0)
		error(2);
	base->scalex = 30;
	base->scaley = -30;
	base->posx = 400;
	base->posy = 400;
	base->view = 1;
	base->color = 0xFFFFFF;
	base->height = params(filebase, 1);
	base->width = params(filebase, 2);
	base->map = (t_pnt **)malloc(sizeof(t_pnt *) * base->height);
	while (count < base->height)
	{
		base->map[count] = (t_pnt *)malloc(sizeof(t_pnt) * base->widht);
		count++;
	}
	read(filebase, base);
}
