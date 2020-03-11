/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:10:24 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/11 22:36:17 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrixer(int *matrixl, char *line)
{
	char	**temp;
	int		x;

//	printf("10\n");
//	printf("%s\n", line);
	temp = ft_strsplit(line, ' ');
//	printf("11\n");
	x = 0;
	while (temp[x])
	{
		matrixl[x] = ft_atoi(temp[x]);
	//	printf("%d  ", matrixl[x]);
		free(temp[x]);
		x++;
	}
//	printf("\n");
	free(temp);
//	free(line);
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

int		widther(char *map)
{
	int		fd;
	char	*line;
	int		res;

	fd = open(map, O_RDONLY, 0);
	get_next_line(fd, &line);
	res = widthertwo(line, ' ');
	free(line);
	close(fd);
	return (res);
}

int		heighter(char *map)
{
	int		fd;
	char	*line;
	int		res;

	res = 0;
	if ((fd = open(map, O_RDONLY, 0)) == -1)
		messaggerror("File does not exist!\n");
	while(get_next_line(fd, &line))
	{
		res++;
		free(line);
	}
	close(fd);
	return (res);
}

void	reader(t_info *base, char *map)
{
	int		fd;
	int		x;
	char	*line;

	x = 0;
//	printf("4\n");
	base->h = heighter(map);
//	printf("5\n");
	base->w = widther(map);
//	printf("6\n");
	base->matrix = (int **)malloc(sizeof(int*) * (base->h + 1));
	while (x <= base->h)
		base->matrix[x++] = (int*)malloc(sizeof(int) * (base->w + 1));
	x = 0;
//	printf("7\n");
	fd = open(map, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
//		printf("8\n");
		matrixer(base->matrix[x], line);
		free(line);
		x++;
//		printf("9\n");
	}
	close(fd);
	base->matrix[x] = NULL;
}
