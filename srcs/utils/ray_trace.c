#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

//https://www.youtube.com/watch?v=ggHSrlrP5zI 
//a quick video about cameras in a raytracer
static void	cam_to_origin(t_matrix *cam, t_rt *rt)
{
	t_vec	up;
	t_vec	right;

	right = v_normalize(v_cross(rt->cam.n, v_new(0,1,0)));
	up = v_cross(rt->cam.n, right);
	cam->m[0][0] = right.x;
	cam->m[0][1] = right.y;
	cam->m[0][2] = right.z;
	cam->m[0][3] = 0; 
	cam->m[1][0] = up.x;
	cam->m[1][1] = up.y;
	cam->m[1][2] = up.z;
	cam->m[1][3] = 0;
	cam->m[2][0] = rt->cam.n.x;
	cam->m[2][1] = rt->cam.n.y;
	cam->m[2][2] = rt->cam.n.z;
	cam->m[2][3] = 0;
	cam->m[3][0] = rt->cam.coord.x;
	cam->m[3][1] = rt->cam.coord.y;
	cam->m[3][2] = rt->cam.coord.z;
	cam->m[3][3] = 1;
}

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
		dist = sphere_intersection(rt->sph, ray, rt);
		if (dist < catched && dist != -1 && dist < 100) // si esta mas cerca que el anterior objeto y si el rayo intersecta
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
		dist = cylinder_intersection(rt->cy, ray, rt);
		if (dist < catched && dist != -1 && dist < 100)
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
		dist = plane_intersection(rt->pl, ray, rt);
		if (dist < catched && dist > 0 && dist < 100) // si esta mas cerca que el anterior onbjeto y si el rayo intersecta
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
	cam_to_origin(&rt->m_cam, rt);
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
