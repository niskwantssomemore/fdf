#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

typedef struct	s_pnt
{
	int	z;
	int	zn;
	int	xn;
	int	yn;
}		t_pnt;

typedef struct	s_info
{
	void	*mlx;
	void	*win;
	t_pnt	**map;
	int	scalex;
	int	scaley;
	int	posx;
	int	posy;
	int	height;
	int	width;
	int	view;
	size_t	less;
	int	color;
}		t_info;

#endif
