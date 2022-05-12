#include "../../includes/minirt.h"

t_vec matrix_vector(t_matrix m,	t_vec ray)
{
	t_vec	new;

	new.x = m.m[0][0] * ray.x + m.m[1][0] * ray.y + m.m[2][0] * ray.z + m.m[3][0];
	new.y = m.m[0][1] * ray.x + m.m[1][1] * ray.y + m.m[2][1] * ray.z + m.m[3][1];
	new.z = m.m[0][2] * ray.x + m.m[1][2] * ray.y + m.m[2][2] * ray.z + m.m[3][2];
	return (new);
}
