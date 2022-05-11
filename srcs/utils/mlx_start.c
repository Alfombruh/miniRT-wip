#include "../../includes/minirt.h"
#include <stdio.h>

static int close_win(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free_struct(mlx->rt);
		exit (1);
	}
	return (0);
}

static int exit_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_struct(mlx->rt);
	exit (1);
}

static void	mlx_img(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = (int *) mlx_get_data_addr(mlx->img.img, &mlx->img.bpp
			, &mlx->img.line_len, &mlx->img.endian);
	mlx->img.line_len = WIDTH;
}

int mlx_start(t_rt *rt)
{
	t_mlx mlx;
	
	ft_memset(&mlx, 0, sizeof(mlx));
	mlx.rt = rt;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "#M1 CuC0");
	mlx_img(&mlx);
	start_raytrace(rt, &mlx, &mlx.img); //funcion que empiza con RTX
	mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	mlx_hook(mlx.win, 17, 0L<<0, exit_win, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
