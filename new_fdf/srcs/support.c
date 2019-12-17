/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:28:29 by sazalee           #+#    #+#             */
/*   Updated: 2019/12/17 16:52:58 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_abs(int number)
{
	unsigned int	numbertwo;

	numbertwo = (number < 0) ? (unsigned int)-number : number;
	return (numbertwo);
}

int				countw(char *format)
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

int				countlength(char *field, int z)
{
	int count;

	count = 0;
	while (field[z] != ' ' || field[z] != '\0')
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
