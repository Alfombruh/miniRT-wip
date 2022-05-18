#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

static t_vec object_normal(t_inter inter, t_vec hp)
{
	if (inter.type == 1)
		return (v_normalize(v_sub(hp, inter.sph->coord)));
	else if (inter.type == 2)
		return (inter.pl->n);
	else if (inter.type == 3)
		return (v_new(0,0,0));
	else
		return (v_new(0,0,0));
}

static void	ray_tracing(t_rt *rt, t_vec ray)
{
	t_vec hp; //hitpoint
	t_vec n; //the  normal
	t_vec vl; //light vector
	double ls; //light source
	int diff_color;
	int	amb_color;

	hp = v_add(v_scal(ray, rt->inter.dist), rt->cam.coord);
	n = object_normal(rt->inter, hp);
	if (n.x == 0 && n.y == 0 && n.z == 0)
		return ;
	vl = v_normalize(v_sub(rt->light.coord, hp));
	amb_color = amb_light(rt->alight.tRGB, rt->inter.color, rt->alight.ratio);
	ls = rt->light.ratio * v_dot(n, v_normalize(v_sub(rt->light.coord, hp)));
	if (ls < 0.0)
		ls = 0;
	else
		ls *= 1.5;
	diff_color =  color_scal(diff_light(rt->inter.color, rt->light.ratio), ls);
	if (light_intersection(rt, v_add(vl, hp)) == 1 )
		rt->color = color_add(amb_color, diff_color);
	else
		rt->color = color_add(amb_color, 0x000000);
}


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
			ray_tracing(rt, ray);
			img->addr[j * img->line_len + i] = rt->color; 
			rt->color = 0;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
