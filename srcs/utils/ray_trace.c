#include "../../includes/minirt.h"

static int ray_casting(t_rt *rt, int *color, int i, int j)
{
	(void) rt;
	(void) j;
	if ((i >= rt->w / 2 && i <= rt->w) && (j >= rt->h / 2 && j <= rt->h))
	{
		*color = rt->alight.tRGB;
		return (1);
	}
	return (0);
}

static void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	img->addr[y * img->line_len + x] = color;
}

int ray_trace(t_rt *rt, t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;
	int color;

	j = -1;
	(void) img;
	while (++j < rt->h)
	{
		i = -1;
		while (++i < rt->w)
			if (ray_casting(rt, &color, i, j))
			{
				my_mlx_pixel_put(&mlx->img, i, j, color);
				mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, i, j);
			}
	}
	return (0);
}
