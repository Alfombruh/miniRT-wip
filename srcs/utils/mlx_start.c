#include "../../includes/minirt.h"

static int close_win(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit (1);
	}
	return (0);
}

int mlx_start(t_rt *rt)
{
	t_mlx mlx;

	(void) rt;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "#def AUL_T");
	mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
