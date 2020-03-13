/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:17:36 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/13 17:58:24 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <math.h>
# include <mlx.h>
# define WX 1000
# define WY 1000

typedef struct	s_info
{
	int			h;
	int			w;
	int			zoom;
	int			color;
	int			movex;
	int			movey;
	int			flag;
	int			z_scale;
	int			**matrix;
	float		xn;
	float		yn;
	int			zn;
	float		angle;
	int			iso;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_info;

void			reader(t_info *base, char *map);
int				heighterw(char *map, int flag);
int				widthertwo(char const *str, char c);
void			matrixer(int *matrixl, char *line);
void			algorithm(t_info *base, float x, float y);
float			modulerb(float xtemp, float ytemp);
void			draw(t_info *base);
void			isometric(float *x, float *y, int z, t_info *base);
int				interaction(int key, t_info *base);
void			messaggerror(char *str);
void			basedefault(t_info *base);
void			setparams(t_info *base, float *x, float *y, int z);
void			basecolor(int z, t_info *base);
int				interaction(int key, t_info *base);
int				is_key(int key);
void			do_key(int key, t_info *base);
void			cleaner(char **input);
void			randomcolor(t_info *base);

#endif
