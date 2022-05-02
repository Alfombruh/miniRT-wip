#include "vectors.h"

//Dot Product of two vectors https://en.wikipedia.org/wiki/Dot_product
double	v_dot(t_vec v, t_vec w)
{
	return ((v.x * w.x) + (v.y * w.y) + (v.z * w.z));
}

// Cross Product of two vectors https://en.wikipedia.org/wiki/Cross_product
t_vec	v_cross(t_vec v, t_vec w)
{
	t_vec u;

	u.x = (v.y * w.z) - (v.z * w.y);
	u.y = (v.z * w.x) - (v.x * w.z);
	u.z = (v.x * w.y) - (v.y * w.x);
	return (u);
}

