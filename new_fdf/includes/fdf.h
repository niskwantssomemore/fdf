/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:11:35 by sazalee           #+#    #+#             */
/*   Updated: 2019/12/17 16:12:17 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WX 1280
# define WY 720
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

typedef struct	s_pnt
{
	int	z;
	int	zn;
	int	xn;
	int	yn;
}				t_pnt;

typedef struct	s_info
{
	void	*mlx;
	void	*win;
	t_pnt	**map;
	int		scalex;
	int		scaley;
	int		posx;
	int		posy;
	int		height;
	int		width;
	int		view;
	size_t	less;
	int		color;
}				t_info;

#endif
