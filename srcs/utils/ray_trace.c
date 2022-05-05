#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

static t_vec place_ray(t_rt *rt, double i, double j)
{
	double	x;
	double	y;
	double	a_ratio;

	a_ratio = (double) WIDTH / (double) HEIGHT;
	x = (2.0 * ((i + 0.5) / (double) WIDTH) - 1.0) * a_ratio * tan((rt->cam.FOV / 2.0) * (M_PI / 180.0));
	y = (1.0 - (2.0 * (j + 0.5) / (double) HEIGHT)) *  tan((rt->cam.FOV / 2.0) * (M_PI / 180.0));
	return (v_new(x, y, -1)); //orientamos la camara hacia z en -1 por convencion
}

static t_vec ray_casting(t_rt *rt, t_vec ray, int *color)
{
	void	*node;
	double	dist;
	double	catched;

	ray = v_normalize(ray);

	dist = 0;
	catched = INFINITY;
	node = (void *)rt->sph;
	while (rt->sph)
	{
		dist = sphere_intersection(rt->sph, ray);
		if (dist < catched && dist != -1)
		{
			catched = dist;
			*color = rt->sph->tRGB;
		}
		rt->sph = rt->sph->next;
	}
	rt->sph = (t_sph *)node;
	node = (void *)rt->cy;
	while (rt->cy)
	{
		dist = cylinder_intersection(rt->cy, ray);
		if (dist < catched && dist != -1 )
		{
			catched = dist;
			*color = rt->cy->tRGB;
		}
		rt->cy = rt->cy->next;
	}
	rt->cy = (t_cy *)node;
	node = (void *)rt->pl;
	while (rt->pl)
	{
		dist = plane_intersection(rt->pl, ray);
		if (dist < catched && dist > 0)
		{
			catched = dist;
			*color = rt->pl->tRGB;
		}
		rt->pl = rt->pl->next;
	}
	rt->pl = (t_pl *)node;
	return ((t_vec) ray);
}

int start_raytrace(t_rt *rt, t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;
	int color;
	t_vec ray;

	j = -1;
	color = 0;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray = place_ray(rt, i, j);
			ray_casting(rt, ray, &color);
			img->addr[j * img->line_len + i] = color; 
			color = 0;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
