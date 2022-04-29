#include "../../includes/minirt.h"
#include <math.h>

int sphere_intersection(t_rt *rt, t_vec ray)
{
	t_vec	xyz;
	double	tca;
	double	thc;
	double	t0;
	double	t1;
	double	dd;

	xyz = rt->sph->coord;
	tca = v_dot(xyz, ray);
	if (tca < 0)
		return (-1);
	dd = v_dot(xyz, xyz) - tca * tca;
	if (dd > (rt->sph->d / 2) * (rt->sph->d / 2))
		return (-1);
	thc = pow((rt->sph->d / 2) * (rt->sph->d / 2) - dd, 0.5);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (-1);
	}
	return (t0);
}
