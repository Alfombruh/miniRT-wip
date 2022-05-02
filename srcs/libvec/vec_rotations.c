#include "vectors.h"
#include <math.h>

t_vec v_rotatex(t_vec v, double a)
{
	t_vec w;
	
	a *= M_PI / 180.0;
	w.x = v.x * 1.0 + v.y * 0.0 + v.z * 0.0;
	w.y = v.x * 0.0 + v.y * cos(a) + v.z * (sin(a) * (-1.0));
	w.z = v.x * 0.0 + v.y * sin(a) + v.z * cos(a);
	return (w);
}

t_vec v_rotatey(t_vec v, double a)
{
	t_vec w;
	
	a *= M_PI / 180.0;
	w.x = v.x * cos(a) + v.y * 0.0 + v.z * sin(a);
	w.y = v.x * 0.0 + v.y * 1.0 + v.z * 0.0;
	w.z = v.x * (sin(a) * (-1.0)) + v.y * 0.0 + v.z * cos(a);
	return (w);
}

t_vec v_rotatez(t_vec v, double a)
{
	t_vec w;

	a *= M_PI / 180.0;
	w.x = v.x * cos(a) + v.y * (sin(a) * (-1.0)) + v.z * 0.0;
	w.y = v.x * sin(a) + v.y * cos(a) + v.z * 0.0;
	w.z = v.x * 0.0 + v.y * 0.0 + v.z * 1.0;
	return (w);
}
