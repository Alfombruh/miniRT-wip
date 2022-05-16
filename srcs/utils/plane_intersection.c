#include "../../includes/minirt.h"
#include <stdio.h>

double	plane_intersection(t_pl *pl, t_vec ray, t_vec coord)
{
	return (v_dot(pl->n, v_sub(pl->coord, coord)) / v_dot(pl->n, ray));
}
