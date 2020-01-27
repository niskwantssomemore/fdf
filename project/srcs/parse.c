/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:00:12 by tstripeb          #+#    #+#             */
/*   Updated: 2020/01/27 16:57:22 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				params(char *filebase, int count)
{
	char		*line;
	int			fd;
	int			res1;
	int			res2;
	int			temp;

	res1 = 0;
	res2 = 0;
	temp = 0;
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

void			calculatescale(t_info *base)
{
	while (base->scalex * base->width > WX && base->scalex > 0)
		base->scalex -= 1;
	while (base->scaley * base->height < -WY && base->scaley < 0)
		base->scaley += 1;
	if (ft_modul(base->scalex) < ft_modul(base->scaley))
		base->scaley = -(base->scalex);
	else
		base->scalex = -(base->scaley);
}

void			ft_conversion(t_info *base, int x, int y, int flag)
{
	size_t temp;

	if (flag == 0)
	{
		temp = ft_modul(base->map[x][y].z);
		if ((!(base->less) && temp != 0) || (temp < base->less && temp != 0))
			base->less = temp;
	}
	else
	{
		if (!(base->less))
			base->less = 1;
		while (x < base->height)
		{
			while (y < base->width)
			{
				base->map[x][y].z /= base->less;
				base->map[x][y].zn /= base->less;
				y++;
			}
			y = 0;
			x++;
		}
	}
}

void			ft_read(char *filebase, t_info *base, int fd, int x)
{
	int		y;
	char	*line;
	char	**result;

	if ((fd = open(filebase, O_RDONLY)) == -1)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		result = transport(line, countw(line));
		while (*result != NULL)
		{
			base->map[x][y].z = ft_atoi(*result);
			ft_conversion(base, x, y, 0);
			base->map[x][y].zn = base->map[x][y].z;
			y++;
			result++;
		}
		//ft_freetime(result);
		y = 0;
		x++;
	}
	close(fd);
	ft_conversion(base, 0, 0, 1);
	calculatescale(base);
}

void			parse(char *filebase, t_info *base)
{
	int fd;
	int count;
	int x;

	x = 0;
	fd = 0;
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
		base->map[count] = (t_pnt *)malloc(sizeof(t_pnt) * base->width);
		count++;
	}
	ft_read(filebase, base, fd, x);
}
