/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:49:10 by sazalee           #+#    #+#             */
/*   Updated: 2019/10/09 16:29:03 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*spacer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			str[i] = ' ';
	}
	return (str);
}

int		countersplits(char **splitchar)
{
	int i;

	i = 0;
	while (splitchar[i])
		i++;
	return (i);
}

int		ft_getnumber(char *str)
{
	int	i;
	int	result;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	return (sign * result);
}
