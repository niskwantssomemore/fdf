#include "fdf.h"

int	main(int ac, char **av)
{
	t_info *base;

	if (!(base = (t_info *)malloc(sizeof(t_info))))
		return (1);
	check(ac);
	parse(av[1], info);
}
