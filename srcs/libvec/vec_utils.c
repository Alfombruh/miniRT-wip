#include "vectors.h"

t_vec v_new(double x, double y, double z)
{
	t_vec v;
	
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	v_dis(t_vec v, t_vec w)
{
	return (v_mod(v_sub(v, w)));
}
