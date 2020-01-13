/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:00:12 by tstripeb          #+#    #+#             */
/*   Updated: 2019/12/27 13:37:12 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

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
	if (ft_abs(base->scalex) < ft_abs(base->scaley))
		base->scaley = -(base->scalex);
	else
		base->scalex = -(base->scaley);
}

void			ft_conversion(t_info *base, int x, int y, int flag)
{
	size_t temp;

	if (flag == 0)
	{
		temp = ft_abs(base->map[x][y].z);
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
		y = 0;
		x++;
	}
	//FREE(result);
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

void			ft_draw(t_info *base, int x, int y)
{
	int coordn[2];
	int coordk[2];

	coordn[0] = base->map[x][y].xn;
	coordn[1] = base->map[x][y].yn;
	if (y < width - 1)
	{
		coordk[0] = map[x][y + 1].xn;
		coordk[1] = map[x][y + 1].yn;
		draw_1(base, coordn, coordk);
	}
	if (x < height - 1)
	{
		coordk[0] = map[x + 1][y].xn;
		coordk[1] = map[x + 1][y].yn;
		draw_1(base, coordn, coordk);
	}
}

void		draw_1(t_info *base, int *coordn, int *coordk)
{
	int delta[2];
	int sign[2];
	int error[2];

	delta[0] = ft_modul(coordk[0] - coordn[0]);
	delta[1] = ft_modul(coordk[1] - coordn[1]);
	sign[0] = (coordk[0] - coordn[0] > 0 ? 1 : -1);
	sign[1] = (coordk[1] - coordn[1] > 0 ? 1 : -1);
	error[0] = delta[0] - delta[1];
	while (coordn[0] != coordk[0] || coordn[1] != coordk[1])
	{
		mlx_pixel_put(base->mlx, base->win, base->scalex
				+ coordn[0], base->scaley + coordn[1], color);
		error[1] = error[0] * 2;
		if (error[1] > -delta[1])
		{
			error[0] -= delta[1];
			coordn[0] += sign[0];
		}
		if (error[1] < delta[0])
		{
			error[0] += delta[0];
			coordn[1] += sign[1]; 
		}
	}
}
