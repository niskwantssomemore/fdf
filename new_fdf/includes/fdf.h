/* dth************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:11:35 by sazalee           #+#    #+#             */
/*   Updated: 2019/12/27 13:37:20 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WX 1280
# define WY 720
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

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

void			check(int ac);
void			error(int er);
int				params(char *filebase, int count);
void			calculatescale(t_info *base);
void			ft_conversion(t_info *base, int x, int y, int flag);
void			ft_read(char *filebase, t_info *base, int fd, int x);
void			parse(char *filebase, t_info *base);
unsigned int	ft_abs(int number);
int				countw(char *format);
int				countlength(char *field, int z);
char			**transport(char *field, int clines);

#endif
