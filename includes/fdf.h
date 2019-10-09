/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:06:32 by sazalee           #+#    #+#             */
/*   Updated: 2019/10/09 19:49:56 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

typedef	struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			number_lines;
	int			x;
	int			y;
	int			startofx;
	int			startofy;
	int			scaleofx;
	int			scaleofy;
	int			**cords;
	int			*splitcoords;
	int			count;
	char		*oneline;
	char		**splitchar;
}				t_fdf;

void			check_ac(int ac);
char			*spacer(char *str);
int				countersplits(char **splitchar);
int				ft_getnumber(char *str);
void			manylines_coords(t_fdf *fdf, int fd);
void			reader(t_fdf *fdf, int fd);

#endif
