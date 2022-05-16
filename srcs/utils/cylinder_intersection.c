#include "../../includes/minirt.h"
#include <math.h>
#include <stdio.h>

// https://www.youtube.com/watch?v=UTz7ytMJ2yk
// really cool RT in cpp series
// http://www.irisa.fr/prive/kadi/Master_Recherche/cours_CTR/RayTracing.pdf
// those are some slides about raytracing
double	cylinder_intersection(t_cy *cy, t_vec ray, t_vec coord)
{
	double A;
	double B;
	double C;
	double dis;

	if (v_dot(ray, cy->n) < 0.0001)
		return (-1);
	A = pow(ray.x, 2) + pow(ray.y, 2);
	B = 2 * (coord.x + ray.x) + (2 * (coord.y + ray.y));
	C = pow(coord.x, 2) + pow(coord.y, 2) - pow(cy->d / 2.0, 2);
	dis = pow(B, 2) - (4.0 * A * C);
	if (dis < 0)
		return (-1);
	else 
		return (1);
}
