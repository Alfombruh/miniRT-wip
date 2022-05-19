#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

static double disk_intersection(t_cy *cy, t_vec ray, t_vec cam, t_vec coord)
{	
	double	t;
	double	r;
	t_vec	p;
	t_vec	v;

	t = v_dot(cy->n, v_sub(coord, cam)) / v_dot(cy->n, ray);
	if (t > 0.0000000001)
	{
		p = v_scal(v_add(cam, ray), t);
		v = v_sub(p, coord);	
		r = sqrt(v_dot(v, v));
		if (r <= cy->d / 2.0)
			return (t);
		else
			return (0);
	}
	return (0);
}

// https://www.youtube.com/watch?v=UTz7ytMJ2yk
// really cool RT in cpp series
// http://www.irisa.fr/prive/kadi/Master_Recherche/cours_CTR/RayTracing.pdf
// those are some slides about raytracing
double	cylinder_intersection(t_cy *cy, t_vec ray, t_vec coord)
{
	double	t0;
	double	t1;

	t0 = disk_intersection(cy, ray, coord, cy->coord);
	t1 = disk_intersection(cy, ray, coord, v_add(cy->coord, v_scal(cy->n, cy->h)));
	if (t1 > t0)
		return t0;
	return t1;
}
