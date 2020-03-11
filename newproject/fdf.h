#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
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
	int			z_scale;
	int			**matrix;
	float		xn;
	float		yn;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_info;

void			reader(t_info *base, char *map);
int				heighter(char *map);
int				widther(char *map);
int				widthertwo(char const *str, char c);
void			matrixer(int *matrixl, char *line);
void			algorithm(t_info *base, float x, float y);
float			modulerb(float xtemp, float ytemp);
void			draw(t_info *base);
void			isometric(float *x, float *y, int z);
int				interaction(int key, t_info *base);
void			messaggerror(char *str);
void			basedefault(t_info *base);
void			setparams(t_info *base, float *x, float *y);
void			basecolor(int z, int zn, t_info *base);
//void			isometric(float *x, float *y, int z);
//void			algorithm(t_info *base, float x, float y, float xn, float yn);
//void			setparams(t_info *base, float *x, float *y, float *xn, float *yn);

#endif
