/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:23:25 by tstripeb          #+#    #+#             */
/*   Updated: 2019/09/08 19:21:12 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	ft_freetime(char **tmp, int counter)
{
	while (counter >= 0)
	{
		ft_strdel(&tmp[counter]);
		counter--;
	}
	ft_strdel(tmp);
}

int		ft_line_char(t_base *base, char *line)
{
	int		index;
	char	**tmp;

	index = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[index])
		index++;
	if (base->lines == 0)
		base->chars = index;
	else
	{
		if (base->chars != index)
			return (0);
	}
	ft_freetime(tmp, index - 1);
	ft_strdel(&line);
	base->lines++;
	return (1);
}

int		ft_line_char_mal(t_base *base, char *line)
{
	int ret;

	base->lines = 0;
	base->chars = 0;
	while ((ret = get_next_line(base->fd, &line)) > 0)
	{
		if (!ft_line_char(base, line))
			return (0);
	}
	close(base->fd);
	if ((base->fd = open(base->filename, O_RDONLY)) != -1)
		return (0);
	base->map = (int **)malloc(sizeof(int *) * base->lines);
	return (1);
}

int		ft_write_in_base(t_base *base)
{
	char	*line;
	char	**temp;
	int		index;
	int		jndex;
	int		ret;

	line = NULL;
	index = 0;
	printf("lal\n");
	if (!ft_line_char_mal(base, line))
		return (0);
	printf("lel\n");
	while ((ret = get_next_line(base->fd, &line)) > 0)
	{
		printf("ret = %i\n", ret);
		jndex = 0;
		printf("%s\n", line);
		temp = ft_strsplit(line, ' ');
		base->map[index] = (int *)malloc(sizeof(int) * base->chars);
		while (jndex < base->chars)
		{
			base->map[index][jndex] = ft_atoi(temp[jndex]);
			jndex++;
		}
	}
	printf("fd = %i\n", base->fd);
	printf("ret = %i\n", ret);
	index = 0;
	printf("kek\n");
//	printf("%i\n", base->map[0][1]);
/*	while (index < base->lines)
	{
		jndex = 0;
		while (jndex < base->chars)
		{
			printf("kuk\n");
			printf("%i\n", base->map[index][jndex]);
			jndex++;
		}
		index++;
	}*/
	return (1);
}
