#include "../../includes/minirt.h"
#include <stdio.h>

double	plane_intersection(t_pl *pl, t_vec ray)
{
	return (v_dot(pl->n, pl->coord) / v_dot(pl->n, ray));
}
