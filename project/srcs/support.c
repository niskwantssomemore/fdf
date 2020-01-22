/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:28:29 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/22 18:02:48 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				countw(char *format)
{
	int index;
	int counter;

	index = 0;
	counter = 0;
	while (format[index])
	{
		if (format[index] != ' ')
		{
			while (format[index] && format[index] != ' ')
				index++;
			counter++;
		}
		else
			index++;
	}
	return (counter);
}

int				countlength(char *field, int z)
{
	int count;

	count = 0;
	while (field[z] != '\0' || field[z] != ' ')
	{
		count++;
		z++;
	}
	return (count);
}

char			**transport(char *field, int clines)
{
	char	**result;
	int		x;
	int		y;
	int		z;
	int		ccolumn;

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
