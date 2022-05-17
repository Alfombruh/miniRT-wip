#include "../../includes/minirt.h"
#include <math.h>

static int	amb_light(int amb_color, int obj_color, double ratio)
{
	int a_rgb[3];
	int o_rgb[3];

	trgb_rgb(amb_color, a_rgb);
	trgb_rgb(obj_color, o_rgb);
	a_rgb[0] = (double)a_rgb[0] * ratio * (double)o_rgb[0] / 255.0;
	a_rgb[1] = (double)a_rgb[1] * ratio * (double)o_rgb[1] / 255.0;
	a_rgb[2] = (double)a_rgb[2] * ratio * (double)o_rgb[2] / 255.0;
	return (0 << 24 | a_rgb[0] << 16 | a_rgb[1] << 8 | a_rgb[2]);
}

static int	diff_light(int obj, double l_ratio)
{
	int d_rgb[3];
	int o_rgb[3];

	trgb_rgb(obj, o_rgb);
	d_rgb[0] = l_ratio * 255.0 * (double)o_rgb[0];
	d_rgb[1] = l_ratio * 255.0 * (double)o_rgb[1];
	d_rgb[2] = l_ratio * 255.0 * (double)o_rgb[2];
	return (0 << 24 | d_rgb[0] << 16 | d_rgb[1] << 8 | d_rgb[2]);
}

static t_vec object_normal(t_inter inter, t_vec hp)
{
	if (inter.type == 2)
		return (v_normalize(v_sub(hp, inter.sph->coord)));
	else if (inter.type == 1)
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
	int diff_color;
	int	amb_color;

	hp = v_add(v_scal(ray, rt->inter.dist), rt->cam.coord);
	n = object_normal(rt->inter, hp);
	vl = v_normalize(v_sub(rt->light.coord, hp));
	//ray_intersection(rt, v_add(hp, vl));
	amb_color = amb_light(rt->alight.tRGB, rt->inter.color, rt->alight.ratio);
	diff_color = diff_light(rt->inter.color, rt->light.ratio);
	rt->inter.color = color_add(diff_color, amb_color);

	printf("rt->inter.color = %d\n", rt->inter.color);
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
			img->addr[j * img->line_len + i] = rt->inter.color; 
			rt->inter.color = 0;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
