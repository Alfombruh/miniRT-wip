#include "vectors.h"
#include <math.h>
//Definition of a vector and its basics properties https://en.wikipedia.org/wiki/Euclidean_vector#Basic_properties

//returns a vec that is equal to placing v in w's head and then writting another vector from 0 to v's new located head
t_vec	v_add(t_vec *v, t_vec *w)
{	
	t_vec u;
	
	u.x = v->x + w->x;
	u.y = v->y + w->y;
	u.z = v->z + w->z;
	return (u);
}

//return a vec that is vec from w to v
t_vec	v_sub(t_vec *v, t_vec *w)
{	
	t_vec u;
	
	u.x = v->x - w->x;
	u.y = v->y - w->y;
	u.z = v->z - w->z;
	return (u);
}

//make a vec bigger or smaller
void	v_scal(t_vec *v, double scal)
{
	v->x *= scal;
	v->y *= scal;
	v->z *= scal;
}

//gets the lenght of the vecto by doing pythagoras in 3D, wich is basically a dot_product of the product by itself
double v_mod(t_vec v)
{
	return (sqrt(dot_product(&v, &v)));
}

//converts a vector to its unit vector, same as a v_scal but dividing but the module
void v_normalize(t_vec *v)
{
	double	mod;

	mod = v_mod(*v);
	v->x /= mod;
	v->y /= mod;
	v->z /= mod;
}
