#include <stdio.h>
#include "../includes/minirt.h"

int main(int argc, char **argv)
{
	t_rt rt;

	if (argc != 2)
		return (ft_argc());
	if (ft_argvcheck(argv[1]))
		return (ft_error("not .rt file"));
	if (ft_readrt(argv[1], &rt))
		return (ft_error(".rt file bad synstaxis"));
	return (0);
}
