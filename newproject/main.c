#include "fdf.h"

int	interaction(t_info *base, int key)
{
	if (key == 126)
		base->movey -= 10;
	if (key == 125)
		base->movey += 10;
	if (key == 123)
		base->movex -= 10;
	if (key == 124)
		base->movex += 10;
	mlx_clear_window(base->mlx_ptr, base->win_ptr);
	draw(base);
	return (0);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	draw(t_info *base)
{
	int	x;
	int	y;

	y = 0;
	while (y < base->h)
	{
		x = 0;
		while (x < base->w)
		{
			if (x < base->w - 1)
				algorithm(base, x, y, x + 1, y);
			if (y < base->h - 1)
				algorithm(base, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}

float	modulerb(float xtemp, float ytemp)
{
	if (xtemp < 0)
		xtemp = -xtemp;
	if (ytemp < 0)
		ytemp = -ytemp;
	if (xtemp > ytemp)
		return (xtemp);
	else
		return (ytemp);
}

void	algorithm(t_info *base, float x, float y, float xn ,float yn)
{
	float	xtemp;
	float	ytemp;
	int	temp;
	int	z;
	int	zn;

	z = base->matrix[(int)y][(int)x];
	zn = base->matrix[(int)yn][(int)xn];
	x *= base->zoom;
	y *= base->zoom;
	xn *= base->zoom;
	yn *= base->zoom;
	base->color = (z || zn) ? 0x0000FF : 0xFFFFFF;
	isometric(&x, &y, z);
	isometric(&xn, &yn, zn);
	x += base->movex;
	xn += base->movex;
	y += base->movey;
	yn += base->movey;
	xtemp = xn - x;
	ytemp = yn - y;
	temp = modulerb(xtemp, ytemp);
	xtemp /= temp;
	ytemp /= temp;
	while ((int)(x - xn) || (int)(y - yn))
	{
		mlx_pixel_put(base->mlx_ptr, base->win_ptr, x, y, base->color);
		x = xtemp + x;
		y = ytemp + y;
	}
}


void	matrixer(int *matrixl, char *line)
{
	char	**temp;
	int	x;

	temp = ft_strsplit(line, ' ');
	x = 0;
	while (temp[x])
	{
		matrixl[x] = ft_atoi(temp[x]);
		free(temp[x]);
		x++;
	}
	free(temp);
}

int	widthertwo(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	widther(char *map)
{
	int	fd;
	char	*line;
	int	res;

	fd = open(map, O_RDONLY, 0);
	get_next_line(fd, &line);
	res = widthertwo(line, ' ');
	free(line);
	close(fd);
	return (res);
}

int	heighter(char *map)
{
	int	fd;
	char	*line;
	int	res;

	res = 0;
	fd = open(map, O_RDONLY, 0);
	while(get_next_line(fd, &line))
	{
		res++;
		free(line);
	}
	close(fd);
	return (res);
}

void	reader(t_info *base, char *map)
{
	int	fd;
	int	x;
	char	*line;

	x = 0;
	base->h = heighter(map);
	base->w = widther(map);
	base->matrix = (int **)malloc(sizeof(int*) * (base->h + 1));
	while (x <= base->h)
		base->matrix[x++] = (int*)malloc(sizeof(int) * (base->w + 1));
	x = 0;
	fd = open(map, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		matrixer(base->matrix[x], line);
		free(line);
		x++;
	}
	close(fd);
	base->matrix[x] = NULL;
}

int	main(int ac, char **av)
{
	t_info *base;

	base = (t_info*)malloc(sizeof(t_info));
	reader(base, av[1]);
	base->movex = 0;
	base->movey = 0;
	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, 1000, 1000, "FDF");
	base->zoom = 20;
	draw(base);
	mlx_key_hook(base->win_ptr, interaction, base);
	mlx_loop(base->mlx_ptr);
}
