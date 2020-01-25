/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:11:35 by sazalee           #+#    #+#             */
/*   Updated: 2020/01/25 15:46:33 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WX 1280
# define WY 720
# define RED 0x0000FF
# define BLUE 0xFF0000
# define GREEN 0x00FF00
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
void			ft_draw(t_info *base);
void			ft_draw1(t_info *base, int x, int y);
void			ft_draw2(t_info *base, int *coord1, int *coord2);
void			pixelmls(t_info *base, int x, int y, int color);
void			ft_freetime(char **result);
void			mathdraw(t_info *base);
int				mathy(t_info *base, int x, int y);
int				mathx(t_info *base, int x, int y);
int				params(char *filebase, int count);
void			calculatescale(t_info *base);
void			ft_conversion(t_info *base, int x, int y, int flag);
void			ft_read(char *filebase, t_info *base, int fd, int x);
void			parse(char *filebase, t_info *base);
int				countw(char *format);
int				countlength(char *field, int z);
char			**transport(char *field, int clines);
int				button1(int keycode, t_info *base);
int				button2(int keycode, t_info *base);
void			changeview(t_info *base, int flag);
int				mousemove(int click, int x, int y, t_info *base);

#endif
