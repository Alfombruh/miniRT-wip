#ifndef VECTORS_H
#define VECTORS_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

t_vec	v_new(double x, double y, double z);
t_vec	v_scal(t_vec v, double scal);
t_vec	v_cross(t_vec v, t_vec w);
t_vec 	v_rotatex(t_vec v, int a);
t_vec 	v_rotatey(t_vec v, int a);
t_vec 	v_rotatez(t_vec v, int a);
t_vec	v_add(t_vec v, t_vec w);
t_vec	v_sub(t_vec v, t_vec w);
t_vec	v_normalize(t_vec v);
double	v_dis(t_vec v, t_vec w);
double	v_dot(t_vec v, t_vec w);
double	v_mod(t_vec v);

#endif
