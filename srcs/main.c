#include <stdio.h>
#include "../includes/minirt.h"

int main(int argc, char **argv)
{
	t_rt rt;

	if (argc != 2)
		return (ft_argc());
	if (ft_argvcheck(argv[1]))
		return (ft_error("not .rt file", NULL));
	ft_memset(&rt, 0, sizeof(rt));
	rt.h = 360;// 144 180 240 360
	rt.w = 640;// 256 320 426 640
	if (ft_readrt(argv[1], &rt))
		return (ft_error(".rt file bad synstaxis", &rt));
	mlx_start(&rt);
	return (0);
}
