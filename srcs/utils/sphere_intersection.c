#include "../../includes/minirt.h"
#include <math.h>

static void double_swap(double *i, double *j)
{
	double temp;
	
	temp = *i;
	*i = *j;
	*j = temp;
}
	
int sphere_intersection(t_sph *sph, t_vec ray)
{
	t_vec	l;
	double	tca;
	double	thc;
	double	t0;
	double	t1;
	double	dd;
	double	r = sph->d / 2;

	l = sph->coord;
	tca = v_dot(l, ray);
	if (tca < 0)
		return (-1);
	dd = v_dot(l, l) - (tca * tca);
	if (dd > (r * r))
		return (-1);
	thc = pow((r * r) - dd, 0.5);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t1 < t0)
		double_swap(&t0, &t1);
	if (t0 < 0)
	{
		t0 = t1;//if  t0 is negative we use t1 instead
		if (t0 < 0)
			return (-1); //this means that both t0 and t1 are negative
	}
	return (t0);
}
