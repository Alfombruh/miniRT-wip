#include "../../includes/minirt.h"
#include <math.h>

static int infinite_cylinder(t_cy *cy, t_rt *rt)
{
	
}
// https://www.youtube.com/watch?v=UTz7ytMJ2yk
// really cool RTX in cpp series
double	cylinder_intersection(t_cy *cy, t_vec ray, t_rt *rt)
{
	(void) ray;
	t_vec	top;
	
	top = v_add(cy->coord, v_scal(cy->n, cy->h));
	if (infinite_cylinder(cy, rt))
		return (-1);
	return (0);
}
