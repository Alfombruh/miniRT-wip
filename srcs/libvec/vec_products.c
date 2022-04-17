#include "vectors.h"

//Dot Product of two vectors https://en.wikipedia.org/wiki/Dot_product
double	dot_product(t_vec *v, t_vec *w)
{
	double	total;

	total = 0.0;
	total += v->x * w->x;
	total += v->y * w->y;
	total += v->y * w->y;
	return (total);
}

// Cross Product of two vectors https://en.wikipedia.org/wiki/Cross_product
t_vec	cross_product(t_vec *v, t_vec *w)
{
	t_vec u;

	u.x = (v->y * w->z) - (v->z * w->y);
	u.y = (v->z * w->x) - (v->x * w->z);
	u.z = (v->x * w->y) - (v->y * w->x);
	return (u);
}

