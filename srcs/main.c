#include <stdio.h>
#include "../includes/minirt.h"

int main(int argc, char **argv)
{
//	t_rt rt;

	if (argc != 2)
		return (ft_argc());
	if (ft_argvcheck(argv[1]))
		return (ft_error("not .rt file", NULL));
//	ft_memset(&rt, 0, sizeof(rt));
//	rt.h = 1080;
//	rt.w = 1920;
//	if (ft_readrt(argv[1], &rt))
//		return (ft_error(".rt file bad synstaxis", &rt));
//	mlx_start(&rt);
//	free_struct(&rt);
	return (0);
}
