#include "../../includes/minirt.h"
#include <math.h>
/*
static t_vec object_normal(t_in in, t_vec hp)
{
	if (in.type == 1)
		return (v_normalize(v_sub(hp, in.sph->coord)));
	else if (in.type == 2)
		return (in.pl->n);
	else if (in.type == 3)
		return (v_new(0,0,0));
	else
		return (v_new(0,0,0));
}

static void	ray_tracing(t_rt *rt, t_vec ray)
{
	t_vec hp;
	t_vec n;
	t_vec vl;
	t_vec filler;

	hp = v_add(v_scal(ray, rt->in.dist), rt->cam.coord);
	n = object_normal(rt->in, hp);
	vl = v_normalize(v_sub(rt->light.coord, hp));
	filler = v_add(hp, vl);
	ray_intersection(rt, filler);
}*/


int start_raytrace(t_rt *rt, t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;
	t_vec ray;

	j = -1;
	cam_to_origin(&rt->m_cam, rt);
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray = place_ray(rt, i, j);
			ray = ray_transform(rt, ray);
			ray_casting(rt, ray);
			//ray_tracing(rt, ray);
			img->addr[j * img->line_len + i] = rt->inter.color; 
			rt->inter.color = 0;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
