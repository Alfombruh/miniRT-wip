#include "../../includes/minirt.h"
#include <math.h>

static int light_sphere(t_rt *rt, t_vec light, double *dist, t_shame sh)
{
	t_sph	*temp;

	temp = rt->sph;
	while(rt->sph)
	{
		*dist = sphere_intersection(rt->sph, sh.n_light, light);
//		if ((*dist > -0.99999999 && *dist < sh.mod) || fabs(*dist - sh.mod) > 0.000000001)
//		{
//			rt->sph = temp;
//			return (0);
//		}
		rt->sph = rt->sph->next;
	}
	rt->sph = temp;
	return (1);
}

static int light_plane(t_rt *rt, t_vec light, double *dist, t_shame sh)
{
	t_pl	*temp;

	temp = rt->pl;
	while(rt->pl)
	{
		*dist = plane_intersection(rt->pl, sh.n_light, light);
//		if ((*dist > -0.99999999 && *dist < sh.mod) || fabs(*dist - sh.mod) > 0.000000001)
//		{
//			rt->pl = temp;
//			return (0);
//		}
		rt->pl = rt->pl->next;
	}
	rt->pl = temp;
	return (1);
}
/*
static void light_cylinder(t_rt *rt, t_vec light, double *dist, double mod)
{
	t_cy	*temp;

	temp = rt->cy;
	while(rt->cy)
	{
		*dist = cylinder_intersection(rt->cy, light, rt->light.coord);
		if (*dist < *catched && *dist != -1)
			*catched = *dist;
		rt->cy = rt->cy->next;
	}
	rt->cy = temp;
}
*/
int light_intersection(t_rt *rt, t_vec light)
{
	double	dist;
	t_shame	sh;

	dist = 0;
	ft_memset(&sh, 0, sizeof(sh));
	sh.mod = v_mod(v_sub(rt->light.coord, light));
	sh.n_light = v_normalize(v_sub(rt->light.coord, light));
	light_sphere(rt, light, &dist, sh);
	light_plane(rt, light, &dist, sh);
	if ((dist > -0.99999999 && dist < sh.mod) || fabs(dist - sh.mod) > 0.000000001)
		return (1);
	return (0);
	/*
	if (light_sphere(rt, light, &dist, sh) == 0)
		return (0);
	if (light_plane(rt, light, &dist, sh) == 0)
		return (0);
//	light_cylinder(rt, light, &dist, mod);
	return (1);*/
}

