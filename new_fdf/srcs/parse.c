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
	while (format[index])
	{
		if (format[index] == ' ')
			counter++;
		index++;
	}
	return (counter);
}

int		params(char *filebase, int count)
{
	char	*field;
	int		fdf;
	int		counter;
	int		cw;
	int		cw1;

	counter = 0;
	if ((fd = open(filebase, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &field) > 0)
	{
		cw = countw(field);
		if (!counter)
			cw1 = cw;
		else if (cw1 == cw)
			cw1 = cw;
		else if (cw1 != cw)
			break ;
		counter++;
	}
	cw1 = (cw1 == cw ? cw1 : 0);
	close(fd);
	return (count == 1 ? counter : cw1);
}

char	**transport(char *field, int ccolumn, int clines)
{
	char	**result;
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	if (!(result = (char**)malloc(sizeof(char *) * clines + 1)))
		return (NULL);
	while (field[z] != '\0')
	{
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

char	*ft_numbfind(char *field, int index)
{
	char *temp;

	field = field + index;
	temp = field;
	while (*field && (*field != ' '))
		field++;
	*field = '\0';
	return (ft_strdup(temp));
}

void	ft_freenumbers(char **numbers, int count)
{
	while (count--)
		ft_strdel(&(numbers[count]));
	free(*numbers);
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
	fd = open(filebase, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		result = transport(line, function1, function2);

void	parse(char *filebase, t_info *base)
{
	int count;

	initstruct;
	params x2 ;
	malloc;
	read;
}
