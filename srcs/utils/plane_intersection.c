#include "../../includes/minirt.h"
#include <stdio.h>

double	plane_intersection(t_pl *pl, t_vec ray, t_rt *rt)
{
	return (v_dot(pl->n, v_sub(pl->coord, rt->cam.coord)) / v_dot(pl->n, ray));
}
