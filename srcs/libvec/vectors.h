#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

t_vec	v_add(t_vec *v, t_vec *w);
t_vec	v_sub(t_vec *v, t_vec *w);
t_vec	v_new(double x, double y, double z);
t_vec	cross_product(t_vec *v, t_vec *w);
double	v_mod(t_vec v);
double	v_dis(t_vec *v, t_vec *w);
double	dot_product(t_vec *v, t_vec *w);
void	v_normalize(t_vec *v);
void	v_scal(t_vec *v, double scal);

#endif
