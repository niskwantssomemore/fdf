/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:10:24 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/13 17:58:16 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleaner(char **input)
{
	int c;

	c = 0;
	while (input[c])
	{
		free(input[c]);
		c++;
	}
	free(input);
}

void	matrixer(int *matrixl, char *line)
{
	char	**temp;
	int		x;

	temp = ft_strsplit(line, ' ');
	x = 0;
	while (temp[x])
	{
		matrixl[x] = ft_atoi(temp[x]);
		x++;
	}
	cleaner(temp);
}

int		widthertwo(char const *str, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int		heighterw(char *map, int flag)
{
	int		fd;
	char	*line;
	int		res1;
	int		res2;
	int		res;

	res1 = 0;
	res = 0;
	if ((fd = open(map, O_RDONLY, 0)) == -1)
		messaggerror("File does not exist!!!\n");
	while (get_next_line(fd, &line))
	{
		res1++;
		res2 = widthertwo(line, ' ');
		if (res == 0)
			res = res2;
		else if (res != res2)
			messaggerror("Invalid map!!!\n");
		free(line);
	}
	close(fd);
	return (flag == 1 ? res1 : res2);
}

void	reader(t_info *base, char *map)
{
	int		fd;
	int		x;
	char	*line;

	x = 0;
	base->h = heighterw(map, 1);
	base->w = heighterw(map, 2);
	base->matrix = (int **)malloc(sizeof(int *) * base->h);
	while (x < base->h)
	{
		base->matrix[x] = (int *)malloc(sizeof(int) * base->w);
		x++;
	}
	x = 0;
	if ((fd = open(map, O_RDONLY, 0)) == -1)
		messaggerror("File does not exist!!!\n");
	while (get_next_line(fd, &line))
	{
		matrixer(base->matrix[x], line);
		free(line);
		x++;
	}
	close(fd);
}
