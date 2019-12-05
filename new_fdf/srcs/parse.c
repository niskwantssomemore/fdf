/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:00:12 by tstripeb          #+#    #+#             */
/*   Updated: 2019/12/05 17:23:53 by tstripeb         ###   ########.fr       */
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
		//free(field);
	}
	cw1 = (cw1 == cw ? cw1 : 0);
	close(fd);
	return (count == 1 ? counter : cw1);
}

void	baseinstruct(char *filebase)
{
	char	**bfield;
	char	*field;
	int		fd;

	if ((fd = open(filebase, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &field) > 0)
	{
		bfield = str_split(field, countw(field));
	}
}

char	**str_split(char *field, int countnumb)
{
	char	**numbers;
	char	*numb;
	int		count;
	int		index;

	index = 0;
	count = 0;
	if (!(numbers = (char **)ft_memalloc(sizeof(char *) * (countnumb + 1))))
		return (NULL);
	while (count < countnumb)
	{
		if (field[index])
		{
			if (!(numb = numbfind(field, index)))
			{
				ft_freenumb(numbers, count);
				return (NULL);
			}
			numbers[count++] = numb;
			index = ft_strlen(numb) + 2;
		}
	}
	numbers[count] = NULL;
	return (numbers);
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

void	ft_freenumberss(char **numbers, int count)
{
	while (count--)
		ft_strdel(&(numbers[count]));
	free(*numbers);
}
