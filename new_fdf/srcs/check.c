#include "fdf.h"

void	check(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Invalid number of arguments.\n", 2);
		ft_putstr_fd("Usage: ./fdf file.fdf\n", 2);
		exit(0);
	}
}

void	error(int er)
{
	if (er == 1)
		ft_putstr_fd("ERROR: Invalid map\n", 2);
	if (er == 2)
		ft_putstr_fd("ERROR: MLX failed\n", 2);
	exit(0);
}
